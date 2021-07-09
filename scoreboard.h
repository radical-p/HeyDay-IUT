#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QDialog>

namespace Ui {
class scoreboard;
}

class scoreboard : public QDialog
{
    Q_OBJECT

public:
    explicit scoreboard(QWidget *parent = nullptr);
    ~scoreboard();

private:
    Ui::scoreboard *ui;
};

#endif // SCOREBOARD_H
