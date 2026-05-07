#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_btnVolver_menuCliente_lista_clicked()
{
	ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btnConfirmar_venta_clicked()
{
	QString producto = ui->comboMedicamentos->currentText();
	int cantidad = ui->spinBox->value();

	QMessageBox::information(this, "Venta", "Procesando venta de: " + producto);
	QMessageBox::information(this, "Venta", "Se vendieron " + QString::number(cantidad) + " unidades");
}

void MainWindow::on_btnSalir_venta_clicked()
{
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnRealizar_venta_clicked()
{
	ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnSalir_principal_clicked()
{
	this->close();
}

void MainWindow::on_btnSubmenu_clientes_clicked()
{
	ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btnSubmenu_meds_clicked()
{
	ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btnBuscar_por_cedula_clicked()
{
	ui->stackedWidget->setCurrentIndex(5); //hacer arreglos 
}

void MainWindow::on_btnEliminar_cliente_clicked()
{
	ui->stackedWidget->setCurrentIndex(6); //hacer arreglos
}

void MainWindow::on_btnLista_clientes_clicked()
{
	ui->stackedWidget->setCurrentIndex(0); 

	ui->tablaClientes->setRowCount(0); 
	ui->tablaClientes->setColumnCount(3);
	ui->tablaClientes->setHorizontalHeaderLabels({"Id", "Nombre", "Cédula" });

	PharmacySystem::Client** lista = miSistema.getClientsArray();
	int total = miSistema.getClientCount();

	for (int i = 0; i < total; i++) {
		if (lista[i] != nullptr) {
			int fila = ui->tablaClientes->rowCount();
			ui->tablaClientes->insertRow(fila);

			ui->tablaClientes->setItem(fila, 0, new QTableWidgetItem(QString::number(lista[i]->getId())));
			ui->tablaClientes->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(lista[i]->getName())));
			ui->tablaClientes->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(lista[i]->getIdentityCard())));
		}
	}
}

void MainWindow::on_btnRegistrar_cliente_clicked()
{
	ui->stackedWidget->setCurrentIndex(2); //hacer arreglos
}

void MainWindow::on_btnSalir_clientes_clicked()
{
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnTarjeta_fidelidad_clicked()
{
	ui->stackedWidget->setCurrentIndex(2); //hacer arreglos
}

void MainWindow::on_btnActualizar_stock_clicked()
{
	ui->stackedWidget->setCurrentIndex(2); //hacer arreglos
}

void MainWindow::on_btnBuscar_med_clicked()
{
	ui->stackedWidget->setCurrentIndex(2); //hacer arreglos
}

void MainWindow::on_btnEliminar_med_clicked()
{
	ui->stackedWidget->setCurrentIndex(2); //hacer arreglos
}

void MainWindow::on_btnLista_med_clicked()
{
	ui->stackedWidget->setCurrentIndex(2);  //hacer arreglos
}

void MainWindow::on_btnRegistrar_med_clicked()
{
	ui->stackedWidget->setCurrentIndex(2); //hacer arreglos
}

void MainWindow::on_btnSalir_medicamentos_clicked()
{
	ui->stackedWidget->setCurrentIndex(2);
}
