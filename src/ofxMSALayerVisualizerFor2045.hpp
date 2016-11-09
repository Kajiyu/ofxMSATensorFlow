//
//  ofxMSALayerVizualizerFor2045.hpp
//  NNVizTest1
//
//  Created by KajiharaYuma on 2016/11/09.
//
//

#pragma once

#include "ofxMSATFIncludes.h"
#include "ofxMSATFUtils.h"

namespace msa {
    namespace tf {
        class ofxMSATensorFlow;
        class LayerVisualizerFor2045 {
        public:
            /*
             *
             */
            void setup(tensorflow::Session& session, const tensorflow::GraphDef& graph_def, string viz_layer_suffix);
            void setup(Session_ptr session, const GraphDef_ptr graph_def, string viz_layer_suffix) { setup(*session, *graph_def, viz_layer_suffix); }
            
            void update();
            void draw(float _x, float _y, float _w, float _h);
            
        protected:
            vector< vector< std::shared_ptr<ofFloatImage> > > weight_imgs;
            vector<tensorflow::Tensor> output_tensors;
            int vizScene = 0;
            int node_count;
            int nLayers;
        };
    }
}