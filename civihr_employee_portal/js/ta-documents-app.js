angular.module('taDocuments', ['civitasks.appDocuments']).controller('myController', ['$scope', '$rootScope', '$rootElement', '$log', '$uibModal', 'DocumentService', 'FileService', 'config',
  function($scope, $rootScope, $rootElement, $log, $modal, DocumentService, FileService, config) {
    $scope.modalDocument = function(data, e) {
      e && e.preventDefault();
      var DocumentData = DocumentService.get({
        'id': data.id
      });

      DocumentData.then(function(data) {
        // Function to display the modal
        openModalDocument(data[0]);
      });
    }

    /**
     * Opens Document Modal with or without document data
     *
     * @param {object} data
     */
    function openModalDocument(data) {
      var modalInstance = $modal.open({
        appendTo: $rootElement.find('div').eq(0),
        templateUrl: config.path.TPL + 'modal/document.html?v=3',
        controller: 'ModalDocumentCtrl',
        resolve: {
          data: function() {
            return data;
          },
          files: function() {
            if (!data.id || !+data.file_count) {
              return [];
            }

            return FileService.get(data.id, 'civicrm_activity');
          }
        }
      });

      modalInstance.result.then(function(results) {
        $scope.$broadcast('documentFormSuccess', results, data);

        if (results.open) {
          $rootScope.modalDocument(data);
        }
      }, function() {
        $log.info('Modal dismissed');
      });
    }
  }
]);
