#ifndef CUSTOMSTYLE_H
#define CUSTOMSTYLE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QString>
#include <QMessageBox>
class CustomTabStyle : public QProxyStyle
{
    int _width;
    int _height;
public:
    CustomTabStyle(int width,int height)
    {
        _width = width;
        _height = height;
        QString str = QString::asprintf("宽：%d 高：%d",_width,_height);
        QMessageBox::warning(NULL,tr("test"),str);
    }
    QSize sizeFromContents(ContentsType type, const QStyleOption *option,
                           const QSize &size, const QWidget *widget) const
    {
        QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
        if (type == QStyle::CT_TabBarTab) {
            s.transpose();
            s.rwidth() = qMax(s.rwidth(), _width); // 最小宽度
            s.rheight() = qMax(s.rheight(), _height); // 最小高度
        }
        return s;
    }

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
    {
        if (element == CE_TabBarTabLabel) {
            if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
                QRect allRect = tab->rect;

                if (tab->state & QStyle::State_Selected) {
                    painter->save();
                    painter->setPen(0x89cfff);
                    painter->setBrush(QBrush(0x89cfff));
                    painter->drawRect(allRect.adjusted(6, 6, -6, -6));
                    painter->restore();
                }
                QTextOption option;
                option.setAlignment(Qt::AlignCenter);
                if (tab->state & QStyle::State_Selected) {
                    painter->setPen(0xf8fcff);
                }
                else {
                    painter->setPen(0x5d5d5d);
                }
                // allRect.adjust(20,20,-(20),-20);
                painter->drawText(allRect, tab->text, option);
                return;
            }
        }

        if (element == CE_TabBarTab) {
            QProxyStyle::drawControl(element, option, painter, widget);
        }
    }
};
#endif // CUSTOMSTYLE_H
