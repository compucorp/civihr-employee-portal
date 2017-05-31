angular.module('taDocuments', ['civitasks.appDocuments']).controller('ModalController', ['$scope', '$rootScope', '$rootElement', '$log', '$uibModal', 'DocumentService', 'FileService', 'config',
  function ($scope, $rootScope, $rootElement, $log, $modal, DocumentService, FileService, config) {
    this.modalDocument = function (id, role) {

      DocumentService.get({'id': id})
      .then(function (data) {
        // Display the modal
        !!data && openModalDocument(data[0], role);
      }, function (reason) {
        CRM.alert(reason, 'Error', 'error');
      });
    }

    /**
     * Opens Document Modal with or without document data
     *
     * @param {object} data
     */
    function openModalDocument (data, role) {
      var modalInstance = $modal.open({
        appendTo: $rootElement.find('div').eq(0),
        templateUrl: config.path.TPL + 'modal/document.html?v=3',
        controller: 'ModalDocumentCtrl',
        resolve: {
          role: function () {
            return [role];
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

      modalInstance.result.then(function (results) {
        $scope.$broadcast('documentFormSuccess', results, data);

        if (results.open) {
          $rootScope.modalDocument(data);
        }
      }, function () {
        $log.info('Modal dismissed');
      });
    }
  }
]);
