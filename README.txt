# Little_YOLOv4
Little_YOLOv4 is a CUDA C++ computer-vision / object-detection solution based on the much larger darknet / YOLOv4 API. Little_YOLOv4 detects objects in images.

The Little_YOLOv4 folder within the above zipped folder contains 19 C structure-definition files; 1 VCXProj file; and 160 pairs of a function declaration file and a function definition file. Each structure has its own file; each function has its own file. There is no use of the C namespace / 'extern "C" { }'. Every function has an explicit declaration. Every structure definition and every function declaration is wrapped in an inclusion guard. Include statements are minimal and explicit.

darknet-master.zip (downloaded on 06/09/20) was 8.005 MB; Little_YOLOv4.zip is 0.730 MB. One version of darknet (downloaded 06/09/20) when set up to detect objects in dog.jpg in either Debug or Release x64 mode is 499 MB; Little_YOLOv4 when set up to detect objects in dog.jpg in either Debug or Release x64 mode is 289 MB. darknet uses 5 GB of RAM to detect objects in dog.jpg; Little_YOLOv4 uses 3 GB of RAM to detect objects in dog.jpg.
