//
//  ofxMSALayerVizualizerFor2045.cpp
//  NNVizTest1
//
//  Created by KajiharaYuma on 2016/11/09.
//
//

#include "ofxMSALayerVisualizerFor2045.hpp"
#include "ofxMSATensorFlow.h"

namespace msa {
    namespace tf {
        
        void LayerVisualizerFor2045::setup(tensorflow::Session &session, const tensorflow::GraphDef &graph_def, string viz_layer_suffix) {
            std::vector<string> names;
            node_count = graph_def.node_size();
            
            // iterate all nodes
            for(int i=0; i<node_count; i++) {
                auto n = graph_def.node(i);
                if(n.name().find(viz_layer_suffix) != std::string::npos) {
                    names.push_back(n.name());
                }
            }
            
            //run the session, using native tensorflow api
            if(!session.Run({}, names, {}, &output_tensors).ok()) ofLogError() << "Error running network to get viz layers";
            int nlayers = output_tensors.size();
            
            cout << "Node Num" << node_count << endl;
            cout << "Layer Num : " << nlayers << endl;
            
            weight_imgs.resize(nlayers);
            
            for(int l=0; l<nlayers; l++) {
                // weights matrix is a bit awkward
                // each column contains flattened weights for each pixel of the input image for a particular digit
                // i.e. 10 columns (one per digit) and 784 rows (one for each pixel of the input image)
                // we need to transpose the weights matrix to easily get sections of it out, this is easy as an image
                
            }
        }
        
        void LayerVisualizerFor2045::update() {
        }
        
        void LayerVisualizerFor2045::draw(float _x, float _y, float _w, float _h) {
        }
    }
}