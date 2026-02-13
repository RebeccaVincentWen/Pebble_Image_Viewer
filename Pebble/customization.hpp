
#include <QPainter>
#include <QColor>
#include <QPushButton>
#include <QPen>

class Generic_PushButton : public QPushButton{
    Q_OBJECT
    public:
    explicit Generic_PushButton(QWidget* parent = nullptr);

    //Generic_PushButton(){setMouseTracking(true);}

    protected:
    QColor defaultBackgroundColor = QColor::fromRgb(167, 193, 217);
    QColor DefaultColor = QColor::fromRgb(167,193, 217);

    void paintEvent(QPaintEvent *event) override;

    void enterEvent(QEnterEvent *event) override; 
    void leaveEvent(QEvent *event) override;
};
