//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009      Bastian Holst <bastianholst@gmx.de>
//

#ifndef WIKIPEDIAMODEL_H
#define WIKIPEDIAMODEL_H

#include "AbstractDataPluginModel.h"

#include <QtGui/QIcon>
#include <QtGui/QPixmap>

namespace Marble {

class MarbleDataFacade;

const quint32 numberOfArticlesPerFetch = 7;
  
class WikipediaModel : public AbstractDataPluginModel
{
    Q_OBJECT
    
 public:
    WikipediaModel( QObject *parent = 0 );
    ~WikipediaModel();

    void setShowThumbnail( bool show );
 
 protected:
    /**
     * Generates the download url for the description file from the web service depending on
     * the @p box surrounding the view and the @p number of files to show.
     **/
    void getAdditionalItems( const GeoDataLatLonAltBox& box,
                             MarbleDataFacade *facade,
                             qint32 number = 10 );
       
    /**
     * The reimplementation has to parse the @p file and should generate widgets. This widgets
     * have to be scheduled to downloadItemData or could be directly added to the list,
     * depending on if they have to download information to be shown.
     **/
    void parseFile( const QByteArray& file );
    
 private:
    QIcon m_wikipediaIcon;

    bool m_showThumbnail;
};

}

#endif // WIKIPEDIAMODEL_H
