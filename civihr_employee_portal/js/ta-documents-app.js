/* globals angular */

(function(angular) {
  angular.module('taDocuments', ['civitasks.appDocuments'])
    .controller('ModalController', ['$scope', '$rootScope', '$window', '$rootElement', '$log', '$uibModal',
      'DocumentService', 'FileService', 'ContactService', 'AssignmentService', 'config', 'settings',
      function($scope, $rootScope, $window, $rootElement, $log, $modal, DocumentService, FileService,
        ContactService, AssignmentService, config, settings) {
        var vm = {};

        vm.contactIds = [];
        vm.assignmentIds = [];

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
          DocumentService.get({
            'status_id': {
              'NOT IN': config.status.resolve.DOCUMENT
            }
          }).then(function (documents) {
            fetchContactsAssignments (documents);
          });
        })();

        /**
         * Fetches the details of contacts and assignments and caches it for
         * future reference.
         *
         * @param  {array} documentList
         */
        function fetchContactsAssignments (documentList) {

          collectIds(documentList);

          if (vm.contactIds && vm.contactIds.length) {
            ContactService.get({
              'IN': vm.contactIds
            }).then(function (data) {
              ContactService.updateCache(data);
            });
          }

          if (vm.assignmentIds && vm.assignmentIds.length && settings.extEnabled.assignments) {
            AssignmentService.get({
              'IN': vm.assignmentIds
            }).then(function (data) {
              AssignmentService.updateCache(data);
            });
          }
        };

        /**
         * Makes collection of list of contactIds and assignmentIds from the
         * list of available documents
         *
         * @param  {array} documentList
         */
        function collectIds (documentList) {

          vm.contactIds.push(config.LOGGED_IN_CONTACT_ID);

          if (config.CONTACT_ID) {
            vm.contactIds.push(config.CONTACT_ID);
          }

          function collectCId(document) {
            vm.contactIds.push(document.source_contact_id);

            if (document.assignee_contact_id && document.assignee_contact_id.length) {
              vm.contactIds.push(document.assignee_contact_id[0]);
            }

            if (document.target_contact_id && document.target_contact_id.length) {
              vm.contactIds.push(document.target_contact_id[0]);
            }
          }

          function collectAId(document) {
            if (document.case_id) {
              vm.assignmentIds.push(document.case_id);
            }
          }

          angular.forEach(documentList, function (document) {
            collectCId(document);
            collectAId(document);
          });
        };

        /**
         * Opens Document Modal
         *
         * @param {object} data
         * @param {string} role
         */
        function openModalDocument(data, role) {
          var modalInstance = $modal.open({
            appendTo: $rootElement.find('div').eq(0),
            templateUrl: config.path.TPL + 'modal/document.html?v=3',
            controller: 'ModalDocumentCtrl',
            resolve: {
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
        };

        return vm;
      }
    ]);
})(angular);
