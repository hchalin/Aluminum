//
// Created by Hayden Chalin on 11/5/26.
//

#pragma once

#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>

class Renderer {
public:
    Renderer(MTL::Device *pDevice);
    ~Renderer();
    void draw(MTK::View* pView);
private:
    MTL::Device* _pDevice;
    MTL::CommandQueue* _pCommandQueue = nullptr;
    MTL::RenderPipelineState* _pPSO;

};