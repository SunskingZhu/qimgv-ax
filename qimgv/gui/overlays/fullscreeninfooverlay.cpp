#include "fullscreeninfooverlay.h"
#include "ui_fullscreeninfooverlay.h"

FullscreenInfoOverlay::FullscreenInfoOverlay(FloatingWidgetContainer *parent) :
    OverlayWidget(parent),
    ui(new Ui::FullscreenInfoOverlay)
{
    ui->setupUi(this);
    setPosition(FloatingWidgetPosition::TOPLEFT);
    this->setHorizontalMargin(0);
    this->setVerticalMargin(0);
    ui->nameLabel->setText("No file opened");
    if(parent)
        setContainerSize(parent->size());

		hideDelay = 2000;
    visibilityTimer.setSingleShot(true);
    visibilityTimer.setInterval(hideDelay);

		connect(&visibilityTimer, &QTimer::timeout, this, &FullscreenInfoOverlay::hideAnimated);
}

FullscreenInfoOverlay::~FullscreenInfoOverlay() {
    delete ui;
}

void FullscreenInfoOverlay::setInfo(QString pos, QString fileName, QString info) {
    ui->posLabel->setText(pos);
    ui->nameLabel->setText(fileName);
    ui->infoLabel->setText(info);
		this->adjustSize();
}

void FullscreenInfoOverlay::show()
{
	OverlayWidget::show();
}

// "blink" the widget; show then fade out immediately
void FullscreenInfoOverlay::show(int duration)
{
	visibilityTimer.stop();
	OverlayWidget::show();
	// fade out after delay
	visibilityTimer.setInterval(duration);
	visibilityTimer.start();
}