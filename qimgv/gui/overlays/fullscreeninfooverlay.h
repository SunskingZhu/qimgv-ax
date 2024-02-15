#pragma once

#include <QWidget>
#include <QTimer>
#include "gui/customwidgets/overlaywidget.h"

namespace Ui {
class FullscreenInfoOverlay;
}

class FullscreenInfoOverlay : public OverlayWidget {
    Q_OBJECT

public:
    explicit FullscreenInfoOverlay(FloatingWidgetContainer *parent = nullptr);
    ~FullscreenInfoOverlay();
    void setInfo(QString pos, QString fileName, QString info);

		void show();
    void show(int duration);

private:
    Ui::FullscreenInfoOverlay *ui;
		QTimer visibilityTimer;
		int hideDelay;
};
