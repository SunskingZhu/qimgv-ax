#include "FloatingMessage.h"
#include "ui_FloatingMessage.h"

QIV::FloatingMessage::FloatingMessage(QWidget *parent) : QWidget(parent), ui(new Ui::FloatingMessage)
{
	ui->setupUi(this);

	this->setAccessibleName("FloatingMessage");

	this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
	ui->textLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
}

QIV::FloatingMessage::~FloatingMessage()
{
	delete ui;
}

void QIV::FloatingMessage::setIcon(QIV::FloatingMessageIcon icon)
{
	switch (icon) {
		case FloatingMessageIcon::NO_ICON:
		case FloatingMessageIcon::ICON_WARNING:
		case FloatingMessageIcon::ICON_ERROR:
			//ui->iconLabel->setIconPath(":/res/icons/common/notifications/error16.png");
			ui->iconLabel->hide();
			break;

		case FloatingMessageIcon::ICON_DIRECTORY:
			ui->iconLabel->show();
			ui->iconLabel->setIconPath(":/res/icons/common/buttons/panel/folder16.png");
			break;

		case FloatingMessageIcon::ICON_LEFT_EDGE:
			ui->iconLabel->show();
			ui->iconLabel->setIconPath(":/res/icons/common/notifications/dir_start20.png");
			break;

		case FloatingMessageIcon::ICON_RIGHT_EDGE:
			ui->iconLabel->show();
			ui->iconLabel->setIconPath(":/res/icons/common/notifications/dir_end20.png");
			break;

		case FloatingMessageIcon::ICON_SUCCESS:
			ui->iconLabel->show();
			ui->iconLabel->setIconPath(":/res/icons/common/notifications/success16.png");
			break;
	}

	this->adjustSize();
}

void QIV::FloatingMessage::setText(const QString &text)
{
	ui->textLabel->setText(text);
	ui->textLabel->setVisible(text.isEmpty() == false);
	this->adjustSize();
}

void QIV::FloatingMessage::paintEvent(QPaintEvent *event)
{
	QStyleOption option;
	option.initFrom(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}
