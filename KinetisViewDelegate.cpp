//
// Created by Hayden Chalin on 11/3/26.
//

#include "KinetisViewDelegate.h"
/*
 * Constructor
 */
KinetisViewDelegate::KinetisViewDelegate(MTL::Device *pDevice)
    : MTK::ViewDelegate(),
    _pRenderer(std::make_unique<Renderer>(pDevice))
{

}

KinetisViewDelegate::~KinetisViewDelegate() {

}

void KinetisViewDelegate::drawableSizeWillChange(MTK::View *pView, CGSize size) {

}

void KinetisViewDelegate::drawInMTKView(MTK::View *pView) {
    _pRenderer->draw(pView);

}



