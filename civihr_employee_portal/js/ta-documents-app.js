/* globals angular */

(function(angular) {
  angular.module('taDocuments', ['civitasks.appDocuments', 'civitasks.directives'])
    .config(function ($urlRouterProvider, $locationProvider) {
      $locationProvider.html5Mode(true); // This is required to remove # for the URL
      $urlRouterProvider.otherwise('/tasks-and-documents');
    })
    .controller('ModalController', ['$scope', '$rootScope', '$window', '$rootElement', '$log', '$uibModal',
      'DocumentService', 'FileService', 'config', 'settings', 'DateFormat',
      function($scope, $rootScope, $window, $rootElement, $log, $modal, DocumentService, FileService, config,
        settings, DateFormat) {
        var vm = {};
        var availableContacts = false;

        vm.loadingModalData = false;

        /**
         * Gets Document for the given document id and
         * opens Modal with retrived document data
         *
         * @param {integer} id
         * @param {string} role
         */
        vm.modalDocument = function (id, role) {
          $rootScope.$broadcast('ct-spinner-show', 'document-' + id);
          vm.loadingModalData = true;

          DocumentService.get({ id: id })
            .then(function(data) {
              if (!data) {
                throw new Error('Requested Document is not available');
              }

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
            //sets the date format for HR_settings.DATE_FORMAT
            DateFormat.getDateFormat();
            DocumentService.cacheContactsAndAssignments(documents, 'contacts');
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

        /**
         * Watch for the changes in the list of $rootScope.cache.contact.arrSearch
         * Display spinner and hide "open" button until the arrSearch is filled with contacts
         *
         * Note: $rootScope.cache.contact.arrSearch will always contain a
         * contact data (curently logged in contact). So if there are documents,
         * there must be more that one contacts conidering at aleast a target contact in a document
         */
        $rootScope.$watch('cache.contact', function () {
          availableContacts = $rootScope.cache.contact.arrSearch.length > 1;
          $rootScope.$broadcast('ct-spinner-' + (availableContacts ? 'hide' : 'show'));
          vm.loadingModalData = !availableContacts;
        });

        return vm;
      }
    ]);
})(angular);
