/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *farmasystem;
    QLabel *titulo_principal_3;
    QPushButton *btnSubmenu_meds;
    QPushButton *btnSubmenu_clientes;
    QPushButton *btnRealizar_venta;
    QPushButton *btnSalir_principal;
    QWidget *submenu_medicamentos;
    QLabel *titulo_principal;
    QPushButton *btnRegistrar_med;
    QPushButton *btnBuscar_med;
    QPushButton *btnLista_med;
    QPushButton *btnActualizar_stock;
    QPushButton *btnEliminar_med;
    QPushButton *btnSalir_medicamentos;
    QWidget *Realizar_Ventas;
    QLabel *titulo_realizarVenta;
    QLabel *label_id;
    QLineEdit *id_client;
    QLabel *labelmed;
    QLabel *label_cantidad;
    QComboBox *comboMedicamentos;
    QPushButton *btnConfirmar_venta;
    QSpinBox *spinBox;
    QPushButton *btnSalir_venta;
    QWidget *submenu_Clientes;
    QLabel *titulo_principal_2;
    QPushButton *btnRegistrar_cliente;
    QPushButton *btnBuscar_por_cedula;
    QPushButton *btnLista_clientes_;
    QPushButton *btnTarjeta_fidelidad;
    QPushButton *btnEliminar_cliente;
    QPushButton *btnSalir_clientes;
    QWidget *Lista_clientes;
    QLabel *titulo_lista_clientes;
    QTableWidget *tablaClientes;
    QPushButton *btnVolver_menuCliente_lista;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1130, 820);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1241, 891));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(129, 199, 132);"));
        farmasystem = new QWidget();
        farmasystem->setObjectName("farmasystem");
        titulo_principal_3 = new QLabel(farmasystem);
        titulo_principal_3->setObjectName("titulo_principal_3");
        titulo_principal_3->setGeometry(QRect(0, 0, 371, 71));
        titulo_principal_3->setStyleSheet(QString::fromUtf8("font: 30pt \"Cambria\";"));
        btnSubmenu_meds = new QPushButton(farmasystem);
        btnSubmenu_meds->setObjectName("btnSubmenu_meds");
        btnSubmenu_meds->setGeometry(QRect(0, 130, 381, 121));
        btnSubmenu_meds->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnSubmenu_clientes = new QPushButton(farmasystem);
        btnSubmenu_clientes->setObjectName("btnSubmenu_clientes");
        btnSubmenu_clientes->setGeometry(QRect(0, 370, 381, 121));
        btnSubmenu_clientes->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnRealizar_venta = new QPushButton(farmasystem);
        btnRealizar_venta->setObjectName("btnRealizar_venta");
        btnRealizar_venta->setGeometry(QRect(0, 650, 381, 111));
        btnRealizar_venta->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnSalir_principal = new QPushButton(farmasystem);
        btnSalir_principal->setObjectName("btnSalir_principal");
        btnSalir_principal->setGeometry(QRect(920, 370, 211, 151));
        btnSalir_principal->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        stackedWidget->addWidget(farmasystem);
        submenu_medicamentos = new QWidget();
        submenu_medicamentos->setObjectName("submenu_medicamentos");
        titulo_principal = new QLabel(submenu_medicamentos);
        titulo_principal->setObjectName("titulo_principal");
        titulo_principal->setGeometry(QRect(0, 0, 621, 71));
        titulo_principal->setStyleSheet(QString::fromUtf8("font: 30pt \"Cambria\";"));
        btnRegistrar_med = new QPushButton(submenu_medicamentos);
        btnRegistrar_med->setObjectName("btnRegistrar_med");
        btnRegistrar_med->setGeometry(QRect(0, 100, 381, 101));
        btnRegistrar_med->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnBuscar_med = new QPushButton(submenu_medicamentos);
        btnBuscar_med->setObjectName("btnBuscar_med");
        btnBuscar_med->setGeometry(QRect(0, 250, 381, 101));
        btnBuscar_med->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnLista_med = new QPushButton(submenu_medicamentos);
        btnLista_med->setObjectName("btnLista_med");
        btnLista_med->setGeometry(QRect(0, 390, 381, 101));
        btnLista_med->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnActualizar_stock = new QPushButton(submenu_medicamentos);
        btnActualizar_stock->setObjectName("btnActualizar_stock");
        btnActualizar_stock->setGeometry(QRect(0, 530, 381, 101));
        btnActualizar_stock->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnEliminar_med = new QPushButton(submenu_medicamentos);
        btnEliminar_med->setObjectName("btnEliminar_med");
        btnEliminar_med->setGeometry(QRect(0, 660, 381, 101));
        btnEliminar_med->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnSalir_medicamentos = new QPushButton(submenu_medicamentos);
        btnSalir_medicamentos->setObjectName("btnSalir_medicamentos");
        btnSalir_medicamentos->setGeometry(QRect(760, 300, 371, 151));
        btnSalir_medicamentos->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        stackedWidget->addWidget(submenu_medicamentos);
        Realizar_Ventas = new QWidget();
        Realizar_Ventas->setObjectName("Realizar_Ventas");
        titulo_realizarVenta = new QLabel(Realizar_Ventas);
        titulo_realizarVenta->setObjectName("titulo_realizarVenta");
        titulo_realizarVenta->setGeometry(QRect(0, 0, 471, 71));
        titulo_realizarVenta->setStyleSheet(QString::fromUtf8("font: 30pt \"Cambria\";"));
        label_id = new QLabel(Realizar_Ventas);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(0, 100, 141, 41));
        label_id->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 166, 154);\n"
"font: 12pt \"Cambria\";"));
        id_client = new QLineEdit(Realizar_Ventas);
        id_client->setObjectName("id_client");
        id_client->setGeometry(QRect(0, 140, 141, 28));
        id_client->setStyleSheet(QString::fromUtf8("background-color: rgb(172, 231, 239);"));
        labelmed = new QLabel(Realizar_Ventas);
        labelmed->setObjectName("labelmed");
        labelmed->setGeometry(QRect(190, 100, 191, 41));
        labelmed->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 166, 154);\n"
"font: 12pt \"Cambria\";"));
        label_cantidad = new QLabel(Realizar_Ventas);
        label_cantidad->setObjectName("label_cantidad");
        label_cantidad->setGeometry(QRect(420, 100, 101, 41));
        label_cantidad->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 166, 154);\n"
"font: 12pt \"Cambria\";"));
        comboMedicamentos = new QComboBox(Realizar_Ventas);
        comboMedicamentos->setObjectName("comboMedicamentos");
        comboMedicamentos->setGeometry(QRect(190, 140, 191, 28));
        comboMedicamentos->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 166, 154);"));
        btnConfirmar_venta = new QPushButton(Realizar_Ventas);
        btnConfirmar_venta->setObjectName("btnConfirmar_venta");
        btnConfirmar_venta->setGeometry(QRect(610, 100, 381, 101));
        btnConfirmar_venta->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        spinBox = new QSpinBox(Realizar_Ventas);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(420, 140, 101, 29));
        btnSalir_venta = new QPushButton(Realizar_Ventas);
        btnSalir_venta->setObjectName("btnSalir_venta");
        btnSalir_venta->setGeometry(QRect(300, 420, 411, 151));
        btnSalir_venta->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        stackedWidget->addWidget(Realizar_Ventas);
        submenu_Clientes = new QWidget();
        submenu_Clientes->setObjectName("submenu_Clientes");
        titulo_principal_2 = new QLabel(submenu_Clientes);
        titulo_principal_2->setObjectName("titulo_principal_2");
        titulo_principal_2->setGeometry(QRect(0, 0, 471, 71));
        titulo_principal_2->setStyleSheet(QString::fromUtf8("font: 30pt \"Cambria\";"));
        btnRegistrar_cliente = new QPushButton(submenu_Clientes);
        btnRegistrar_cliente->setObjectName("btnRegistrar_cliente");
        btnRegistrar_cliente->setGeometry(QRect(0, 90, 381, 101));
        btnRegistrar_cliente->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnBuscar_por_cedula = new QPushButton(submenu_Clientes);
        btnBuscar_por_cedula->setObjectName("btnBuscar_por_cedula");
        btnBuscar_por_cedula->setGeometry(QRect(0, 230, 381, 101));
        btnBuscar_por_cedula->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnLista_clientes_ = new QPushButton(submenu_Clientes);
        btnLista_clientes_->setObjectName("btnLista_clientes_");
        btnLista_clientes_->setGeometry(QRect(0, 370, 381, 101));
        btnLista_clientes_->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnTarjeta_fidelidad = new QPushButton(submenu_Clientes);
        btnTarjeta_fidelidad->setObjectName("btnTarjeta_fidelidad");
        btnTarjeta_fidelidad->setGeometry(QRect(0, 510, 381, 101));
        btnTarjeta_fidelidad->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnEliminar_cliente = new QPushButton(submenu_Clientes);
        btnEliminar_cliente->setObjectName("btnEliminar_cliente");
        btnEliminar_cliente->setGeometry(QRect(0, 650, 381, 101));
        btnEliminar_cliente->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        btnSalir_clientes = new QPushButton(submenu_Clientes);
        btnSalir_clientes->setObjectName("btnSalir_clientes");
        btnSalir_clientes->setGeometry(QRect(720, 260, 411, 151));
        btnSalir_clientes->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        stackedWidget->addWidget(submenu_Clientes);
        Lista_clientes = new QWidget();
        Lista_clientes->setObjectName("Lista_clientes");
        titulo_lista_clientes = new QLabel(Lista_clientes);
        titulo_lista_clientes->setObjectName("titulo_lista_clientes");
        titulo_lista_clientes->setGeometry(QRect(0, 0, 291, 71));
        titulo_lista_clientes->setStyleSheet(QString::fromUtf8("font: 30pt \"Cambria\";"));
        tablaClientes = new QTableWidget(Lista_clientes);
        if (tablaClientes->columnCount() < 3)
            tablaClientes->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tablaClientes->setObjectName("tablaClientes");
        tablaClientes->setGeometry(QRect(0, 90, 371, 441));
        tablaClientes->setStyleSheet(QString::fromUtf8("background-color: rgb(172, 231, 239);\n"
"color: rgb(165, 108, 193);"));
        btnVolver_menuCliente_lista = new QPushButton(Lista_clientes);
        btnVolver_menuCliente_lista->setObjectName("btnVolver_menuCliente_lista");
        btnVolver_menuCliente_lista->setGeometry(QRect(470, 530, 411, 151));
        btnVolver_menuCliente_lista->setStyleSheet(QString::fromUtf8("font: 20pt \"Cambria\";\n"
"background-color: rgb(38, 166, 154);"));
        stackedWidget->addWidget(Lista_clientes);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1130, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "mainWindow", nullptr));
        titulo_principal_3->setText(QCoreApplication::translate("MainWindow", "FARMASYSTEM", nullptr));
        btnSubmenu_meds->setText(QCoreApplication::translate("MainWindow", "Submenu Medicamentos", nullptr));
        btnSubmenu_clientes->setText(QCoreApplication::translate("MainWindow", "Submenu Clientes", nullptr));
        btnRealizar_venta->setText(QCoreApplication::translate("MainWindow", "Realizar Venta", nullptr));
        btnSalir_principal->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        titulo_principal->setText(QCoreApplication::translate("MainWindow", "SUBMENU MEDICAMENTOS", nullptr));
        btnRegistrar_med->setText(QCoreApplication::translate("MainWindow", "Registrar Medicamento", nullptr));
        btnBuscar_med->setText(QCoreApplication::translate("MainWindow", "Buscar Medicamento", nullptr));
        btnLista_med->setText(QCoreApplication::translate("MainWindow", "Lista de Medicamentos", nullptr));
        btnActualizar_stock->setText(QCoreApplication::translate("MainWindow", "Actualizar Stock", nullptr));
        btnEliminar_med->setText(QCoreApplication::translate("MainWindow", "Eliminar Medicamento", nullptr));
        btnSalir_medicamentos->setText(QCoreApplication::translate("MainWindow", "Volver al menu principal", nullptr));
        titulo_realizarVenta->setText(QCoreApplication::translate("MainWindow", "REALIZAR VENTAS", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "ID del Cliente:", nullptr));
        labelmed->setText(QCoreApplication::translate("MainWindow", "ID del Medicamento:", nullptr));
        label_cantidad->setText(QCoreApplication::translate("MainWindow", "Cantidad:", nullptr));
        btnConfirmar_venta->setText(QCoreApplication::translate("MainWindow", "Confirmar Venta", nullptr));
        btnSalir_venta->setText(QCoreApplication::translate("MainWindow", "Volver al menu principal", nullptr));
        titulo_principal_2->setText(QCoreApplication::translate("MainWindow", "SUBMENU CLIENTES", nullptr));
        btnRegistrar_cliente->setText(QCoreApplication::translate("MainWindow", "Registrar Cliente", nullptr));
        btnBuscar_por_cedula->setText(QCoreApplication::translate("MainWindow", "Buscar por C\303\251dula", nullptr));
        btnLista_clientes_->setText(QCoreApplication::translate("MainWindow", "Lista de Clientes", nullptr));
        btnTarjeta_fidelidad->setText(QCoreApplication::translate("MainWindow", "Tarjeta de Fidelidad", nullptr));
        btnEliminar_cliente->setText(QCoreApplication::translate("MainWindow", "Eiminar Cliente", nullptr));
        btnSalir_clientes->setText(QCoreApplication::translate("MainWindow", "Volver al menu principal", nullptr));
        titulo_lista_clientes->setText(QCoreApplication::translate("MainWindow", "Lista Clientes", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablaClientes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaClientes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaClientes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "C\303\251dula", nullptr));
        btnVolver_menuCliente_lista->setText(QCoreApplication::translate("MainWindow", "Volver al Submenu Clientes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
