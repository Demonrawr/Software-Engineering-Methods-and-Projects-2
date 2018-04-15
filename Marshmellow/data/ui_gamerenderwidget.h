/********************************************************************************
** Form generated from reading UI file 'gamerenderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMERENDERWIDGET_H
#define UI_GAMERENDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameRenderWidget
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *GameRenderWidget)
    {
        if (GameRenderWidget->objectName().isEmpty())
            GameRenderWidget->setObjectName(QStringLiteral("GameRenderWidget"));
        GameRenderWidget->resize(400, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameRenderWidget->sizePolicy().hasHeightForWidth());
        GameRenderWidget->setSizePolicy(sizePolicy);
        GameRenderWidget->setMinimumSize(QSize(400, 600));
        gridLayout = new QGridLayout(GameRenderWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        retranslateUi(GameRenderWidget);

        QMetaObject::connectSlotsByName(GameRenderWidget);
    } // setupUi

    void retranslateUi(QWidget *GameRenderWidget)
    {
        GameRenderWidget->setWindowTitle(QApplication::translate("GameRenderWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameRenderWidget: public Ui_GameRenderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMERENDERWIDGET_H
