//
// Created by Hayden Chalin on 11/5/26.
//

#include "Renderer.h"

Renderer::Renderer(MTL::Device *pDevice):
    _pDevice(pDevice),
   _pPSO(nullptr),
    _commandQueue(NS::TransferPtr(_pDevice->newCommandQueue()))
{

}
Renderer::~Renderer() {

}
void Renderer::draw(MTK::View *pView) {
    NS::AutoreleasePool* pPool = NS::AutoreleasePool::alloc()->init();

    MTL::CommandBuffer* commandBuffer = _commandQueue->commandBuffer();
    MTL::RenderPassDescriptor* pRpd = pView->currentRenderPassDescriptor();
    MTL::RenderCommandEncoder* pEncoder = commandBuffer->renderCommandEncoder(pRpd);

    pEncoder->endEncoding();
    commandBuffer->presentDrawable(pView->currentDrawable());
    commandBuffer->commit();

    pPool->release();

}


