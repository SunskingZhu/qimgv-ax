#include "FloatingMessages.h"

#include <QVBoxLayout>
#include <QTimer>

#include "settings.h"

QIV::FloatingMessages::FloatingMessages(FloatingWidgetContainer *parent) : OverlayWidget(parent)
{
	position = FloatingWidgetPosition::BOTTOMLEFT;

	QVBoxLayout *layout = new QVBoxLayout();
	layout->setSizeConstraint(QLayout::SetMinimumSize);
	layout->setDirection(QBoxLayout::BottomToTop);
	layout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(layout);

	setFadeEnabled(true);
	setFadeDuration(300);

	readSettings();

	connect(settings, &Settings::settingsChanged, this, &FloatingMessages::readSettings);

	if (parent) {
		setContainerSize(parent->size());
	}
}

void QIV::FloatingMessages::readSettings()
{
    /*
    // don't interfere with the main panel
    if(settings->panelEnabled() && settings->panelPosition() == PanelHPosition::PANEL_BOTTOM) {
        m_position = FloatingWidgetPosition::TOP;
    } else {
        m_position = FloatingWidgetPosition::BOTTOM;
    }
    */
}

void QIV::FloatingMessages::mousePressEvent(QMouseEvent */*event*/)
{}

QIV::FloatingMessage *QIV::FloatingMessages::addMessage(const QString &text, QIV::FloatingMessageIcon icon, int duration)
{
	QIV::FloatingMessage *message = new QIV::FloatingMessage(this);
	message->setText(text);
	message->setIcon(icon);

	connect(message, &QWidget::destroyed, this, [message, this] () {
		QLayout *layout = this->layout();
		layout->removeWidget(message);
		this->adjustSize();
		if (layout->count() == 0) {
			this->hide();
		}
	});

	this->layout()->addWidget(message);

	this->show();

	if (duration >= 0) {
		QTimer *timer = new QTimer(this);

		connect(timer, &QTimer::timeout, message, &QWidget::deleteLater);
		connect(timer, &QTimer::timeout, timer, &QTimer::deleteLater);

		timer->setSingleShot(true);
		timer->setInterval(duration);
		timer->start();
	}

	return message;
}

void QIV::FloatingMessages::error(const QString &text)
{
	this->addMessage(text, QIV::FloatingMessageIcon::ICON_ERROR, DURATION_ERROR);
}

void QIV::FloatingMessages::warning(const QString &text)
{
	this->addMessage(text, QIV::FloatingMessageIcon::ICON_WARNING, DURATION_WARNING);
}

void QIV::FloatingMessages::success(const QString &text)
{
	this->addMessage(text, QIV::FloatingMessageIcon::ICON_SUCCESS, DURATION_SUCCESS);
}

void QIV::FloatingMessages::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
	this->recalculateGeometry();
}
