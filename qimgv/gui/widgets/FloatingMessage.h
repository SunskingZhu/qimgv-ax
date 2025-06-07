#pragma once

#include <QWidget>

namespace QIV
{
	namespace Ui {
		class FloatingMessage;
	}

	enum FloatingMessageIcon {
		NO_ICON,
		ICON_DIRECTORY,
		ICON_LEFT_EDGE,
		ICON_RIGHT_EDGE,
		ICON_SUCCESS,
		ICON_WARNING,
		ICON_ERROR
	};

	class FloatingMessage : public QWidget
	{
		Q_OBJECT
	public:
		explicit FloatingMessage(QWidget *parent = 0);
		~FloatingMessage();

	public slots:
		void setIcon(FloatingMessageIcon icon);
		void setText(const QString &text);

	protected:
		void paintEvent(QPaintEvent *event);

	private:
		Ui::FloatingMessage *ui;
	};
} // QIV
