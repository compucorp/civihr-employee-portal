/* globals angular */

(function(angular) {
  angular.module('taDocuments', ['civitasks.appDocuments', 'civitasks.directives'])
    .config(function ($urlRouterProvider, $locationProvider) {
      $locationProvider.html5Mode(true); // This is required to remove # for the URL
      $urlRouterProvider.otherwise('/tasks-and-documents');
    })
    .controller('ModalController', ['$scope', '$rootScope', '$window', '$rootElement', '$log', '$uibModal',
      'DocumentService', 'FileService', 'config', 'settings',
      function($scope, $rootScope, $window, $rootElement, $log, $modal, DocumentService, FileService, config, settings) {
        var vm = {};
        var isContactsCached = {};

        vm.loadingModalData = false;

        /**
         * Gets Document for the given document id and
         * opens Modal with retrived document data
         *
         * @param {integer} id
         * @param {string} role
         */
        vm.modalDocument = function (id, role) {
          DocumentService.get({ id: id })
            .then(function(data) {
              if (!data) {
                throw new Error('Requested Document is not available');
              }

              $rootScope.$broadcast('ct-spinner-show');
              vm.loadingModalData = true;

              openModalDocument(data[0], role);
            })
            .catch(function(reason) {
              CRM.alert(reason, 'Error', 'error');
            });
        };

        (function init() {
          // Reloads page on 'document-saved' event
          $rootScope.$on('document-saved', function () {
            $window.location.reload();
          });
          // Get list of documents
          DocumentService.get().then(function (documents) {
            isContactsCached = DocumentService.cacheContactsAndAssignments(documents, 'contacts');
          });
        })();

        /**
         * Opens Document Modal
         *
         * @param {object} data
         * @param {string} role
         */
        function openModalDocument(data, role) {
          var modalInstance = $modal.open({
            appendTo: $rootElement,
            templateUrl: config.path.TPL + 'modal/document.html?v=3',
            controller: 'ModalDocumentCtrl',
            resolve: {
              modalMode: function () {
                return '';
              },
              role: function () {
                return role;
              },
              data: function () {
                return data;
              },
              isContactsCached: isContactsCached,
              files: function () {
                if (!data.id || !+data.file_count) {
                  return [];
                }

                return FileService.get(data.id, 'civicrm_activity');
              }
            }
          });

          modalInstance.opened.then(function () {
            $rootScope.$broadcast('ct-spinner-hide');
            vm.loadingModalData = false;
          });
        };

        return vm;
      }
    ]);
})(angular);
