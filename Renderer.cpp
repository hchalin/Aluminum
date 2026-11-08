//
// Created by Hayden Chalin on 11/5/26.
//

#include "Renderer.h"

Renderer::Renderer(MTL::Device *pDevice):
    _pDevice(pDevice),
   _PSO(nullptr),
    _commandQueue(NS::TransferPtr(_pDevice->newCommandQueue()))
{

}
Renderer::~Renderer() {

}
void Renderer::draw(MTK::View *pView) {

    //* Auto Release Pool, no need to call release()
    auto pool = NS::TransferPtr(NS::AutoreleasePool::alloc()->init());

    //* Command Buffer
    auto* commandBuffer = _commandQueue->commandBuffer();
    if (!commandBuffer) return;

    //* Get the current render pass from view
    auto* renderPass = pView->currentRenderPassDescriptor();
    if (!renderPass) return;
    auto* pEncoder = commandBuffer->renderCommandEncoder(renderPass);

    //* Encode Commands

    //* Stop Encodeing
    pEncoder->endEncoding();

    //* Get drawable
    auto* drawable = pView->currentDrawable();
    if (!drawable || !renderPass) return;   // Skip this frame

    //* Present and Commit
    commandBuffer->presentDrawable(drawable);
    commandBuffer->commit();


}


