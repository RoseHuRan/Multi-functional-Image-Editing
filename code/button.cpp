
#include "button.h"

Button::Button(QWidget *parent)
    : QPushButton(parent)
{
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Preferred );
    this->setStyleSheet("background:transparent");
//    this->setStyleSheet("color: white");
    this->setIconSize(QSize(120,40));
}

Button::~Button() {

}

void Button::setButtonPicture(QPixmap *pic){
    ButtonPicture = pic;
    this->setIcon(QIcon(*ButtonPicture));
}

void Button::setPressPicture(QPixmap *pic){
    PressPicture = pic;
}

void Button::setButtonSize(int width,int height){
    this->setIconSize(QSize(width, height));
}

//void Button::setMode(int mode){
//    this->mode = mode;
//}

void Button::mousePressEvent(QMouseEvent *event){
    Q_UNUSED(event);
    this->setIcon(QIcon(*PressPicture));
    emit clicked();
}

void Button::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    this->setIcon(QIcon(*ButtonPicture));
    emit released();
}



//void Button::enterEvent(QEvent *event){
//    Q_UNUSED(event);
//    this->setIcon(QIcon(*hoverPicture));
//}
//void Button::leaveEvent(QEvent *event){
//    Q_UNUSED(event);
//    this->setIcon(QIcon(*buttonPicture));
//}
