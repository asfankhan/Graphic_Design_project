//Demonstrating connecting the Qt Tree View widget to another class (like a scene graph)

#include <iostream>
#include <sstream>
#include <string>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"


Window::Window(QWidget *parent) :  // Window constructor
    QWidget(parent),
    ui(new Ui::Window)
{
	ui->setupUi(this);				// Standard Qt stuff

	ui->horizontalSlider->setMinimum(0); ui->horizontalSlider->setMaximum(5); ui->horizontalSlider->setSingleStep(1);

	connect(ui->listWidget, &QListWidget::currentRowChanged, this, &Window::on_treeWidget_currentItemChanged);
	connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Window::on_horizontalSlider_valueChanged);
	connect(ui->extrudeButton, &QPushButton::clicked, this, &Window::on_clicked_extrudeButton);

	connect(ui->btnRot, &QPushButton::clicked, this, &Window::on_buttonPress_valueChanged);
	
	connect(ui->Create, &QPushButton::clicked, this, &Window::on_Create_Press);
	connect(ui->pushButton, &QPushButton::clicked, this, &Window::on_wired);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &Window::on_solid);

	connect(ui->pushButton_3, &QPushButton::clicked, this, &Window::on_view_top);
	connect(ui->pushButton_4, &QPushButton::clicked, this, &Window::on_view_side);

	connect(ui->pushButton_5, &QPushButton::clicked, this, &Window::on_change_color);

	connect(ui->pushButton_6, &QPushButton::clicked, this, &Window::on_change_height);

	connect(ui->pushButton_7, &QPushButton::clicked, this, &Window::Fractalizefunc);
	connect(ui->pushButton_8, &QPushButton::clicked, this, &Window::SubDividefunc);
	connect(ui->pushButton_9, &QPushButton::clicked, this, &Window::capHeightfunc);

	QString s = QString::number(ui->myGLWidget->cam->getEye()[0]);
	ui->lblX->setText("X: " + s);
	s = QString::number(ui->myGLWidget->cam->getEye()[1]);
	ui->lblY->setText("Y: " + s);
	s = QString::number(ui->myGLWidget->cam->getEye()[2]);
	ui->lblZ->setText("Z: " + s);

}

Window::~Window()
{
    delete ui;
}
void Window::capHeightfunc()
{
	QString val = ui->lineEdit_10->text();
	float val1 = val.toFloat();
	ui->myGLWidget->capHeight = val1;
	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::SubDividefunc()
{

	ui->myGLWidget->rowsize *= 2;
	ui->myGLWidget->colsize *= 2;

	ui->myGLWidget->win->controller->resizePlane(ui->myGLWidget->rowsize, ui->myGLWidget->colsize, ui->myGLWidget->depth, ui->myGLWidget->width);

	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::Fractalizefunc()
{
	float Height = (rand() % 200)*.01;

	for (int j = 0; j < ui->myGLWidget->win->numPolys(); j++)
	{
		Height = (rand() % 100* ui->myGLWidget->depth)*.01;

		gVector temp = ui->myGLWidget->win->getPoly(j).getCol(1);

		for (int i = 0; i < ui->myGLWidget->win->numPolys(); i++)
		{
			gVector v1 = ui->myGLWidget->win->getPoly(i).getCol(0);
			gVector v2 = ui->myGLWidget->win->getPoly(i).getCol(1);
			gVector v3 = ui->myGLWidget->win->getPoly(i).getCol(2);
			gVector v4 = ui->myGLWidget->win->getPoly(i).getCol(3);


			QString val = ui->lineEdit_9->text();
			float val1 = val.toFloat();

			if (temp[0] == v1[0] && temp[2] == v1[2])
			{
				ui->myGLWidget->win->controller->faces[i]->points[1][0] = Height;
			}
			if (temp[0] == v2[0] && temp[2] == v2[2])
			{
				ui->myGLWidget->win->controller->faces[i]->points[1][1] = Height;
			}
			if (temp[0] == v3[0] && temp[2] == v3[2])
			{
				ui->myGLWidget->win->controller->faces[i]->points[1][2] = Height;
			}
			if (temp[0] == v4[0] && temp[2] == v4[2])
			{
				ui->myGLWidget->win->controller->faces[i]->points[1][3] = Height;
			}
		}
	}

	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_Create_Press()
{
	QString val = ui->lineEdit->text();
	float val1 = val.toFloat();
	val = ui->lineEdit_2->text();
	float val2 = val.toFloat();
	val = ui->lineEdit_3->text();
	float val3 = val.toFloat();
	val = ui->lineEdit_4->text();
	float val4 = val.toFloat();


	ui->myGLWidget->rowsize = val1;
	ui->myGLWidget->colsize = val2;

	ui->myGLWidget->depth = val4;
	ui->myGLWidget->width = val3;

	ui->myGLWidget->win->controller->createPlane(val1, val2, val4, val3);
	//controller->createPlane(5, 5, 5, 5);
	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_change_height()
{
//	gVector temp = ui->myGLWidget->win->getPoly(ui->myGLWidget->selectedFace).set(i,1,5);
	for (int i = 0; i < ui->myGLWidget->win->numPolys(); i++)
	{
		gVector v1 = ui->myGLWidget->win->getPoly(i).getCol(0);
		gVector v2 = ui->myGLWidget->win->getPoly(i).getCol(1);
		gVector v3 = ui->myGLWidget->win->getPoly(i).getCol(2);
		gVector v4 = ui->myGLWidget->win->getPoly(i).getCol(3);

		gVector temp = ui->myGLWidget->win->getPoly(ui->myGLWidget->selectedFace).getCol(1);

		QString val = ui->lineEdit_9->text();
		float val1 = val.toFloat();

		if (temp[0] == v1[0] && temp[2] == v1[2])
		{
			ui->myGLWidget->win->controller->faces[i]->points[1][0] = val1;
		}
		if (temp[0] == v2[0] && temp[2] == v2[2])
		{
			ui->myGLWidget->win->controller->faces[i]->points[1][1] = val1;
		}
		if (temp[0] == v3[0] && temp[2] == v3[2])
		{
			ui->myGLWidget->win->controller->faces[i]->points[1][2] = val1;
		}
		if (temp[0] == v4[0] && temp[2] == v4[2])
		{
			ui->myGLWidget->win->controller->faces[i]->points[1][3] = val1;
		}
		//v1[1] = 5;
		
			//= ui->myGLWidget->win->getPoly(2).get;

		//ui->myGLWidget->win->getPoly(i).getCol(0)[1] = 5
	}


	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_view_top()
{

	ui->myGLWidget->cam->eye = gVector(0, 0, 5, 1);
	ui->myGLWidget->cam->rot = gMatrix::identityMatrix(4);
	ui->myGLWidget->cam->increasePhi(90);

	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_view_side()
{
	ui->myGLWidget->cam->eye = gVector(0, 0, 5, 1);
	ui->myGLWidget->cam->rot = gMatrix::identityMatrix(4);
	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_change_color()
{
	QString val = ui->lineEdit_5->text();
	float val1 = val.toFloat();
	val = ui->lineEdit_6->text();
	float val2 = val.toFloat();
	val = ui->lineEdit_7->text();
	float val3 = val.toFloat();

	ui->myGLWidget->colx = val1;
	ui->myGLWidget->coly = val2;
	ui->myGLWidget->colz = val3;

	ui->myGLWidget->update();
}
void Window::on_wired()
{

	ui->myGLWidget->wired = true;
	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_solid()
{
	ui->myGLWidget->wired = false;
	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}
void Window::on_buttonPress_valueChanged(int value)
{
	startTimer(100);
	// Update the OpenGL window
	ui->myGLWidget->update();  // Note in this sample code it will not do anything. In yours it should 
}

void Window::timerEvent(QTimerEvent *event)
{
	ui->myGLWidget->cam->increaseTheta(-7);
	ui->myGLWidget->update();
	
	qDebug() << "Timer ID:" << event->timerId();
}
void Window::keyPressEvent(QKeyEvent *e)  // If the user hits esc, close the program. 
{
    if (e->key() == Qt::Key_Escape)
        close();
	else if (e->key() == Qt::Key_A)
	{
		ui->myGLWidget->cam->increaseTheta(-7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_D)
	{
		ui->myGLWidget->cam->increaseTheta(7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_W)
	{
		ui->myGLWidget->cam->increasePhi(-7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_S)
	{
		ui->myGLWidget->cam->increasePhi(7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_E)
	{
		ui->myGLWidget->cam->increaseRad(-0.5);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_F)
	{
		ui->myGLWidget->cam->increaseRad(0.5);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_K)
	{
		if (ui->myGLWidget->win->controller->numPolys() == ui->myGLWidget->selectedFace + 1)
		{
			ui->myGLWidget->selectedFace = 0;
		}
		else {
			ui->myGLWidget->selectedFace = ui->myGLWidget->selectedFace + 1;
		}
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_I)
	{
		if (ui->myGLWidget->selectedFace - 1<0)
		{
			ui->myGLWidget->selectedFace = ui->myGLWidget->win->controller->numPolys() -1;
		}
		else {
			ui->myGLWidget->selectedFace = ui->myGLWidget->selectedFace - 1;
		}
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_J)
	{
		if (0 > ui->myGLWidget->selectedFace - ui->myGLWidget->rowsize)
		{
			ui->myGLWidget->selectedFace = ui->myGLWidget->win->controller->numPolys()+ ui->myGLWidget->selectedFace - ui->myGLWidget->rowsize ;
		}
		else {
			ui->myGLWidget->selectedFace = ui->myGLWidget->selectedFace - ui->myGLWidget->rowsize;
		}
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_L)
	{

		if (ui->myGLWidget->win->controller->numPolys() <= ui->myGLWidget->selectedFace + ui->myGLWidget->rowsize)
		{
			ui->myGLWidget->selectedFace = ui->myGLWidget->selectedFace + ui->myGLWidget->rowsize - ui->myGLWidget->win->controller->numPolys();
		}
		else {
			ui->myGLWidget->selectedFace = ui->myGLWidget->selectedFace + ui->myGLWidget->rowsize;
		}
		ui->myGLWidget->update();
	}
    else
        QWidget::keyPressEvent(e);

	QString s = QString::number(ui->myGLWidget->cam->getEye()[0]);
	ui->lblX->setText("X: " + s);
	s = QString::number(ui->myGLWidget->cam->getEye()[1]);
	ui->lblY->setText("Y: " + s);
	s = QString::number(ui->myGLWidget->cam->getEye()[2]);
	ui->lblZ->setText("Z: " + s);
}
void Window::mousePressEvent(QMouseEvent* event)
{
	lastPos = event->pos();
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		ui->myGLWidget->cam->increasePhi(dx);
		ui->myGLWidget->cam->increaseTheta(dy);
	}
	else if (event->buttons() & Qt::RightButton) {
		ui->myGLWidget->cam->increasePhi(dx);
		ui->myGLWidget->cam->increaseTheta(dy);
	}

	lastPos = event->pos();
}

void Window::setController(Controller* c)
{
	this->controller = c; 
}

void Window::updateBrowser()		// update the face browser
{
	for (int i = ui->listWidget->count(); i < controller->numPolys(); i++)
	{
		ui->listWidget->addItem("Face"); 
	}
}

void Window::select(int selected) 		// set the selection
{
	QListWidgetItem *item = ui->listWidget->item(selected);
	ui->listWidget->setCurrentItem(item);
}

void Window::updateDrawing() 			// redraw the OpenGL window
{
	ui->myGLWidget->update(); 
}

const int Window::numPolys()			// get the number of faces
{
	return controller->numPolys();
}

gMatrix Window::getPoly(int i)			// get a face
{
	return controller->getPoly(i);
}

const int Window::getSelected()					// get the index of the face selected
{
	return controller->getSelected();
}

const float Window::getExtrude()			  // return the distance to extrude to. 
{
	return ui->horizontalSlider->value();
}

void Window::on_treeWidget_currentItemChanged(int value)
{
	controller->select(value); //  ui->listWidget->currentRow());
}

void Window::on_horizontalSlider_valueChanged(int value)
{
	
	// not doing anything interactive with the slider. See getExtrude
}

void Window::on_clicked_extrudeButton()
{
	controller->extrudeSelected(this->getExtrude());
}