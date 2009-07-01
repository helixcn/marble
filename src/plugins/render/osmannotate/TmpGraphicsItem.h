//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009      Andrew Manson <g.real.ate@gmail.com>
//

#ifndef TMPGRAPHICSITEM_H
#define TMPGRAPHICSITEM_H

#include <QtCore/QRect>
#include <QtCore/QObject>
#include <QtGui/QPainterPath>

#include "GeoGraphicsItem.h"
#include "GeoDataLatLonAltBox.h"
#include "marble_export.h"

namespace Marble {



class MARBLE_EXPORT TmpGraphicsItem : public GeoGraphicsItem
{
public:
    TmpGraphicsItem();
    ~TmpGraphicsItem();

enum GeoGraphicsItemChange {
    ItemPositionChange,
    ItemSelectChange
};

    //method will be removed when we decide how to do the general case of
    //a hit test. Waiting for tackat to do "The Maths"
//    virtual QRect screenBounding() = 0 ;
    // same as above
//    virtual void geoBounding(qreal angularResolution) = 0;

    virtual void paint(GeoPainter * painter, ViewportParams * viewport, const QString &renderPos, GeoSceneLayer *layer) =0 ;

    //Designed to recreated the QGraphicsItem::itemChange()
    virtual QVariant itemChange( GeoGraphicsItemChange change, QVariant Value );
    //this is just so that i can test the implementation
    QList<QPainterPath>  m_regions;

    QList<TmpGraphicsItem*> getChildren();
    void addChild(TmpGraphicsItem* c);

    TmpGraphicsItem* getParent();
    void setParent( TmpGraphicsItem* p );

    //determines if this object is offset from its parent
    //by geocoorninates. If it is not then then it is drawn as screen
    //coordinate offset from its parent.
    //ONLY valid if there is a parent object.
    //FIXME remove this? is this needed at all?
    bool isGeoOffset();

protected:
    //FIXME remove this? is this needed at all?
    void setGeoOffset( bool g );

 private:
    //intended to go in the private class
    QList<TmpGraphicsItem*> children;

    //Allows for the implementation of local coordinate systems
    //for children objects
    TmpGraphicsItem* parent;

    bool geoOffset;




};

}

#endif // TMPGRAPHICSITEM_H
