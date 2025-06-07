#pragma once

#include "gui/customwidgets/overlaywidget.h"
#include "gui/widgets/FloatingMessage.h"

namespace QIV
{
	class FloatingMessages : public OverlayWidget
	{
	Q_OBJECT
	public:
		static constexpr int DURATION_FOREVER = -1;
		static constexpr int DURATION_DEFAULT = 1700;
		static constexpr int DURATION_SUCCESS = 1500;
		static constexpr int DURATION_WARNING = 1500;
		static constexpr int DURATION_ERROR = 2800;

		FloatingMessages(FloatingWidgetContainer *parent);

		FloatingMessage *addMessage(const QString &text, FloatingMessageIcon icon = NO_ICON, int duration = DURATION_DEFAULT);

	public slots:
		void error(const QString &text);
		void warning(const QString &text);
		void success(const QString &text);

	protected:
		void mousePressEvent(QMouseEvent *event);
		virtual void resizeEvent(QResizeEvent *event);

	private slots:
		void readSettings();
	};
}
