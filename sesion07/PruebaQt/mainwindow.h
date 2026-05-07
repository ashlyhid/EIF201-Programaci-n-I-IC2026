#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "PharmacySystem.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	void on_btnVolver_menuCliente_lista_clicked();
	void on_btnConfirmar_venta_clicked();
	void on_btnSalir_venta_clicked();
	void on_btnRealizar_venta_clicked();
	void on_btnSalir_principal_clicked();
	void on_btnSubmenu_clientes_clicked();
	void on_btnSubmenu_meds_clicked();
	void on_btnBuscar_por_cedula_clicked();
	void on_btnEliminar_cliente_clicked();
	void on_btnLista_clientes_clicked();
	void on_btnRegistrar_cliente_clicked();
	void on_btnSalir_clientes_clicked();
	void on_btnTarjeta_fidelidad_clicked();
	void on_btnActualizar_stock_clicked();
	void on_btnBuscar_med_clicked();
	void on_btnEliminar_med_clicked();
	void on_btnLista_med_clicked();
	void on_btnRegistrar_med_clicked();
	void on_btnSalir_medicamentos_clicked();
private:
    Ui::MainWindow* ui;
    PharmacySystem::PharmacySystem miSistema;
};
#endif