
#include "layer.h"


int yolo_num_detections(layer l, float thresh)
{
    // Start a count of the number of detections for the present YOLO layer.
    int numberOfDetections = 0;
 
    int indexOfAnchorBoxAmongAnchorBoxes;
    int numberOfAnchorBoxesPerYOLOLayer = l.n;
    int indexOfGridCellInChannelOfPredictionTensor;
    int numberOfGridCellsInChannelOfPredictionTensor = l.w * l.h;
    int indexOfObjectnessScoreInPredictionTensor;
    int indexOfInputImageInSubdivision = 0;
    int numberOfElementsInPredictionSubtensor = l.outputs;
    int numberOfElementsInPredictionForObject = 4 + 1 + l.classes;
    int indexOfObjectnessScoreInPredictionForObject = 4;

    // For each of three anchor boxes associated with the present YOLO layer,
    for (indexOfAnchorBoxAmongAnchorBoxes = 0;
         indexOfAnchorBoxAmongAnchorBoxes < numberOfAnchorBoxesPerYOLOLayer;
         ++indexOfAnchorBoxAmongAnchorBoxes) {

        // For each grid cell in the prediction tensor
        // associated with the present YOLO layer,
        for (indexOfGridCellInChannelOfPredictionTensor = 0;
             indexOfGridCellInChannelOfPredictionTensor < numberOfGridCellsInChannelOfPredictionTensor;
             ++indexOfGridCellInChannelOfPredictionTensor) {

            // Find the index of the objectness score corresponding to
            // - the one input image,
            // - the present anchor box, and
            // - the present grid cell.
            indexOfObjectnessScoreInPredictionTensor =
                indexOfInputImageInSubdivision * numberOfElementsInPredictionSubtensor +
                indexOfAnchorBoxAmongAnchorBoxes * numberOfGridCellsInChannelOfPredictionTensor * numberOfElementsInPredictionForObject +
                indexOfObjectnessScoreInPredictionForObject * numberOfGridCellsInChannelOfPredictionTensor +
                indexOfGridCellInChannelOfPredictionTensor;
            
            // If the objectness score is greater than float thresh,
            // increment the number of detections for the present yolo layer.
            if (l.output[indexOfObjectnessScoreInPredictionTensor] > thresh) {
                ++numberOfDetections;
            }
        }
    }

    // Return the number of detections for the present YOLO layer.
    return numberOfDetections;
}