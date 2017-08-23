/* globals angular */

(function(angular) {
  angular.module('taDocuments', ['civitasks.appDocuments', 'civitasks.directives'])
    .config(function ($urlRouterProvider, $locationProvider) {
      $locationProvider.html5Mode(true); // This is required to remove # for the URL
      $urlRouterProvider.otherwise('/tasks-and-documents');
    })
    .controller('ModalController', ModalController);

    ModalController.$inject = ['$scope', '$rootScope', '$window', '$rootElement', '$log', '$uibModal',
      'DocumentService', 'FileService', 'config', 'settings', 'DateFormat'];

    function ModalController ($scope, $rootScope, $window, $rootElement, $log, $modal, DocumentService, FileService, config,
      settings, DateFormat) {
        var availableContacts = false;
        var vm = this;

        vm.loadingModalData = false;

        vm.modalDocument = modalDocument;
        vm.openModalDocument = openModalDocument;

        (function init() {
          subscribeForEvents();
          watchForChanges();
          collectRequiredData();
        })();

        /**
         * Collect required data for document modal
         */
        function collectRequiredData () {
          // Sets the date format for HR_settings.DATE_FORMAT
          DateFormat.getDateFormat();

          // Fetch and cache contacts and addignments
          DocumentService.get().then(function (documents) {
            DocumentService.cacheContactsAndAssignments(documents, 'contacts');
          });
        };

        /**
         * Gets Document for the given document id and
         * opens Modal with retrived document data
         *
         * @param {integer} id
         * @param {string} role
         * @param {string} mode
         */
        function modalDocument (id, role, mode) {
          $rootScope.$broadcast('ct-spinner-show', 'document-' + id);
          vm.loadingModalData = true;

          DocumentService.get({ id: id })
            .then(function(data) {
              if (!data) {
                throw new Error('Requested Document is not available');
              }

              vm.openModalDocument(data[0], role, mode);
            })
            .catch(function(reason) {
              CRM.alert(reason, 'Error', 'error');
            });
        };

        /**
         * Opens Document Modal
         *
         * @param {object} data
         * @param {string} role
         * @param {string} mode
         */
        function openModalDocument(data, role, mode) {
          var modalInstance = $modal.open({
            appendTo: $rootElement,
            templateUrl: config.path.TPL + 'modal/document.html?v=3',
            controller: 'ModalDocumentController',
            controllerAs: 'documentModal',
            resolve: {
              modalMode: function () {
                return mode;
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
        }

        /**
         * All event subscribers
         */
        function subscribeForEvents () {
          $rootScope.$on('document-saved', function () {
            $window.location.reload();
          });
        };

        /**
         * All watchers for changes
         */
        function watchForChanges () {
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
        };
    }
})(angular);
