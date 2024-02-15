#pragma once

#include "gui/overlays/fullscreeninfooverlay.h"

struct InfoOverlayStateBuffer {
    QString position;
    QString fileName;
    QString info;
    bool showImmediately = false;
		int duration = 0;
};

class FullscreenInfoOverlayProxy {
public:
    explicit FullscreenInfoOverlayProxy(FloatingWidgetContainer *parent = nullptr);
    ~FullscreenInfoOverlayProxy();
    void init();
    void show();
    void showWhenReady();
		void showWhenReady(int duration);
    void hide();
    void setInfo(QString position, QString fileName, QString info);

private:
    FloatingWidgetContainer *container;
    FullscreenInfoOverlay *infoOverlay;
    InfoOverlayStateBuffer stateBuf;
};
