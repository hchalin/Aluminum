//
// Created by Hayden Chalin on 11/3/26.
//

#include "AluminumViewDelegate.h"
/*
 * Constructor
 */
AluminumViewDelegate::AluminumViewDelegate(MTL::Device *pDevice)
    : MTK::ViewDelegate(),
    _pRenderer(std::make_unique<Renderer>(pDevice))
{

}

AluminumViewDelegate::~AluminumViewDelegate() {

}

void AluminumViewDelegate::drawableSizeWillChange(MTK::View *pView, CGSize size) {

}

void AluminumViewDelegate::drawInMTKView(MTK::View *pView) {

}



