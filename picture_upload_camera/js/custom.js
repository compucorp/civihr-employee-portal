(function($) {
    
    Drupal.behaviors.picture_upload_camera_snapshot = {
        attach: function (context, settings) {
            
            // Look after different browser vendors' ways of calling the getUserMedia()
            // API method:
            // Opera --> getUserMedia
            // Chrome --> webkitGetUserMedia
            // Firefox --> mozGetUserMedia
            navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia;
            
            // Use constraints to ask for a video-only MediaStream:
            var constraints = {audio: false, video: true};
            var video = document.querySelector("video");
            var width = 320;
            var height = 240;

            // Default brightness
            var brightness = 0;

            // Set default streamed video size
            video.setAttribute('width', width);
            video.setAttribute('height', height);

            // Callback to be called in case of success...
            function successCallback(stream) {

                // Note: make the returned stream available to console for inspection
                window.stream = stream;
                if (window.URL) {
                    
                    // Chrome case: URL.createObjectURL() converts a MediaStream to a blob URL
                    video.src = window.URL.createObjectURL(stream);
                    
                } else {
                    
                    // Firefox and Opera: the src of the video can be set directly from the stream
                    video.src = stream;
                }

                // We're all set. Let's just play the video out!
                video.play();

                // Make the video stream visible
                videoStream.style.display = "inline";

                // Make the take photo button visible when we have the stream
                takePhoto.style.display = "inline";

                // Hide the camera INIT button
                loadCamera.style.display = "none";
            }

            // Callback to be called in case of failures...
            function errorCallback(error){
                console.log("navigator.getUserMedia error: ", error);
            }
            
            /** 
             * Save the captured photo in the canvas (this canvas will have the filters applied later)
             */
            function takepicture() {

                canvas.width = width;
                canvas.height = height;
                canvas.getContext('2d').drawImage(video, 0, 0, width, height);

            }
           
            /**
             * 
             * @param {type} ctx
             * @param {type} image
             * @param {type} filter_type
             * @returns {undefined}
             */
            function applyFilter(filter_type, brightness) {

                // Make the slider visible
                sliderLabel.style.display = "inline";
                
                var ctx = canvas.getContext("2d");
                var new_img = document.getElementById("modified-image");
                new_img.width = width;
                new_img.height = height;

                var modified_canvas = new_img.getContext("2d");
                var imgData = ctx.getImageData(0, 0, width, height);

                // If brightness is passed set the brightness value
                if (brightness) {

                    // Set the brightness if needed
                    final_image = Filters.brightness(imgData, brightness);

                }
                if (filter_type == 'sobel') {

                    // get the grayscale filter first as we need it for the sobel filter
                    var grayscale = Filter['grayscale'](imgData);
                    var vertical = Filters.convoluteFloat32(grayscale,
                        [-1, 0, 1,
                         -2, 0, 2,
                         -1, 0, 1]);
                    var horizontal = Filters.convoluteFloat32(grayscale,
                        [-1, -2, -1,
                         0, 0, 0,
                         1, 2, 1]);

                    final_image = modified_canvas.createImageData(vertical.width, vertical.height);

                    for (var i = 0; i < final_image.data.length; i += 4) {

                        // make the vertical gradient red
                        var v = Math.abs(vertical.data[i]);
                        final_image.data[i] = v;

                        // make the horizontal gradient green
                        var h = Math.abs(horizontal.data[i]);
                        final_image.data[i + 1] = h;

                        // and mix in some blue for aesthetics
                        final_image.data[i + 2] = (v + h) / 4;
                        final_image.data[i + 3] = 255; // opaque alpha
                    }

                }
                else {

                    // No advanced processing needed just filter the image
                    final_image = Filter[filter_type](imgData);

                }

                modified_canvas.putImageData(final_image, 0, 0);

                // @TODO for later -> should we allow to put some custom text on the image and drag and drop where we want to?
                // modified_canvas.fillText("Hello World!",10,50);

                // Output the modified canvas as jpg
                var data = new_img.toDataURL('image/jpeg');

                // Set the modified image in the PHOTO div (this will show in the browser)
                photo.setAttribute('src', data);
                
                // Set the modified image in the hidden field (this will be sent after form submit to Drupal for processing)
                hiddenimage.setAttribute('value', data);
               
            }

            var loadCamera = document.querySelector("button#loadCameraButton");
            var hiddenimage = document.querySelector('input[name="picture_upload_camera_value"]');
            var takePhoto = document.querySelector("button#takePhotoButton");
            var inverse = document.querySelector("button#inverseType");
            var grayscale = document.querySelector("button#grayscaleType");
            var sobel = document.querySelector("button#sobelType");
            var videoStream = document.querySelector("video#video-stream");
            var mainCanvas = document.querySelector("canvas#canvas");
            var sliderLabel = document.querySelector("p#slider-label");

            var init_slider = function() {

                // Show the slider
                $("#slider").css("display", "inline");

                $("#slider").slider({
                    orientation: "vertical",
                    range: "min",
                    min: -100,
                    max: 100,
                    value: brightness,
                    change: function(event, ui) {
                        console.log('changed');
                    },
                    slide: function(event, ui) {

                        // Reapply the filter and set the brightness
                        applyFilter(Filter.filter_type, ui.value * 2);
                        $("#amount").val(ui.value);
                    }
                });

                $("#amount").val($("#slider").slider("value"));

            }

            /**
             * Onclick event to initialise the camera
             */
            loadCamera.onclick = function () {

                // Main action: just call getUserMedia() on the navigator object
                navigator.getUserMedia(constraints, successCallback, errorCallback);

                return false;
            }

            /**
             * Onclick event for taking the snapshot
             */
            takePhoto.onclick = function () {

                // Reset the brightness value
                brightness = 0;

                takepicture();

                // Show the filters when the picture is ready
                inverse.style.display = "inline";
                grayscale.style.display = "inline";
                sobel.style.display = "inline";

                // Show the main canvas so we can see the picture snap
                mainCanvas.style.display = "inline";
                
                return false;
            }

            inverse.onclick = function () {

                // Set what filter will be called
                Filter.filter_type = 'inverse';

                // Apply selected filter
                applyFilter(Filter.filter_type);

                // Allow to set brightness with the slider
                init_slider();

                return false;

            };
            
            grayscale.onclick = function () {
                
                // Set what filter will be called
                Filter.filter_type = 'grayscale';

                // Apply selected filter
                applyFilter(Filter.filter_type);

                // Allow to set brightness with the slider
                init_slider();

                return false;

            };

            sobel.onclick = function () {

                // Set what filter will be called
                Filter.filter_type = 'sobel';

                // Apply selected filter
                applyFilter(Filter.filter_type);

                // Allow to set brightness with the slider
                init_slider();

                return false;

            };
            
            Filter = {};

            Filter.grayscale = function (pixels, args) {
                var d = pixels.data;
                for (var i = 0; i < d.length; i += 4) {
                    var r = d[i];
                    var g = d[i + 1];
                    var b = d[i + 2];
                    d[i] = d[i + 1] = d[i + 2] = (r + g + b) / 3;
                }

                return pixels;
            };
            
            Filter.inverse = function (pixels, args) {
                var d = pixels.data;

                for (var i = 0;i < d.length; i += 4) {
                    d[i] = 255 - d[i];
                    d[i + 1] = 255 - d[i + 1];
                    d[i + 2] = 255 - d[i + 2];
                    d[i + 3] = 255;
                }

                return pixels;
            };

            Filters = {};

            if (!window.Float32Array) Float32Array = Array;

            Filters.brightness = function(pixels, adjustment) {
                var ptr = pixels.data;
                var len = ptr.length;
                for (var i = 0; i < len; i += 4)  {
                    ptr[i] += adjustment;
                    ptr[i + 1] += adjustment;
                    ptr[i + 2] += adjustment;
                }
                return pixels;
            };

            Filters.convoluteFloat32 = function(pixels, weights, opaque) {
                var side = Math.round(Math.sqrt(weights.length));
                var halfSide = Math.floor(side / 2);

                var src = pixels.data;
                var sw = pixels.width;
                var sh = pixels.height;

                var w = sw;
                var h = sh;
                var output = {
                    width: w, height: h, data: new Float32Array(w*h*4)
                };
                var dst = output.data;

                var alphaFac = opaque ? 1 : 0;

                for (var y = 0; y < h; y++) {
                    for (var x = 0; x < w; x++) {
                        var sy = y;
                        var sx = x;
                        var dstOff = (y * w +x) * 4;
                        var r = 0, g = 0, b = 0, a = 0;
                        for (var cy = 0; cy < side; cy++) {
                            for (var cx = 0; cx < side; cx++) {
                                var scy = Math.min(sh - 1, Math.max(0, sy + cy - halfSide));
                                var scx = Math.min(sw - 1, Math.max(0, sx + cx - halfSide));
                                var srcOff = (scy * sw + scx)*4;
                                var wt = weights[cy * side + cx];
                                r += src[srcOff] * wt;
                                g += src[srcOff + 1] * wt;
                                b += src[srcOff + 2] * wt;
                                a += src[srcOff + 3] * wt;
                            }
                        }
                        dst[dstOff] = r;
                        dst[dstOff + 1] = g;
                        dst[dstOff + 2] = b;
                        dst[dstOff + 3] = a + alphaFac * (255 - a);
                    }
                }
                return output;
            };

        }
    }
})(jQuery);