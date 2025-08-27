/***************************************************************************
                          qgsabout.h  -  description
                             -------------------
    begin                : Sat Aug 10 2002
    copyright            : (C) 2002 by Gary E.Sherman
    email                : sherman at mrcc.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef QGSABOUT_H
#define QGSABOUT_H

#include "ui_qgsabout.h"
#include "qgsoptionsdialogbase.h"
#include "qgis_app.h"

class APP_EXPORT QgsAbout : public QgsOptionsDialogBase, private Ui::QgsAbout
{
    Q_OBJECT
  public:
    QgsAbout( QWidget *parent );

    void setVersion( const QString &v );
    static QString fileSystemSafe( const QString &string );

  private:
    // TODO kestrel  注释：UI中已隐藏"What's New"页面，相关函数已注释
    // TODO kestrel void setWhatsNew();
    void setLicence();
    void setPluginInfo();
    // TODO kestrel 注释：UI中已隐藏开发者地图页面，相关函数已注释
    // TODO kestrel void setDevelopersMap();
    void init();
    QString mVersionString;

  private slots:
    void btnCopyToClipboard_clicked();
    // TODO kestrel 注释：UI中已隐藏用户邮件列表按钮，相关槽函数已注释
    // TODO kestrel void btnQgisUser_clicked();
    // TODO kestrel 注释：UI中已隐藏主页按钮，相关槽函数已注释
    // TODO kestrel void btnQgisHome_clicked();
    void openUrl( const QUrl &url );
};

#endif
