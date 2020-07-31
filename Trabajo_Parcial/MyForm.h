#pragma once
#include "CLista_Enlazada.h"
#include"CLista_Dob_Circular.h"
#include"CLista_Dob_Enlazada.h"
#include"Lista_Circular.h"
#include"Lista_Enlazada_PF.h"
#include"Lista_Circular_PF.h"
#include"Lista_Doble_PF.h"

namespace Trabajo_Parcial {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		CLista_Enlazada* objCLista_Enlazada;
		ListaDob*objListaDoble;
		Lista_Circular*objListaCircular;
		Lista_Dob_Circular*objListaDobCirc;
		CLista_Simple_PF*objLista_SimplePF;
		ListaDobPF*objListaDobPF;
		Lista_CircularPF*objListaCirPF;

		int selected = -1;

	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label1;
			 Graphics^g;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = this->CreateGraphics();
			objCLista_Enlazada = new CLista_Enlazada();
			objListaDoble = new ListaDob();
			objListaCircular = new Lista_Circular();
			objListaDobCirc = new Lista_Dob_Circular();
			objLista_SimplePF = new CLista_Simple_PF();
			objListaDobPF = new ListaDobPF();
			objListaCirPF = new Lista_CircularPF();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  btnInicio;
	private: System::Windows::Forms::Button^  btnFinal;
	private: System::Windows::Forms::Button^  btnPosicion;
	private: System::Windows::Forms::Button^  btnEliminar;
	private: System::Windows::Forms::TextBox^  txtDato;

	private: System::Windows::Forms::Label^  lblDato;
	private: System::Windows::Forms::Label^  lblImprinir;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnInicio = (gcnew System::Windows::Forms::Button());
			this->btnFinal = (gcnew System::Windows::Forms::Button());
			this->btnPosicion = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->txtDato = (gcnew System::Windows::Forms::TextBox());
			this->lblDato = (gcnew System::Windows::Forms::Label());
			this->lblImprinir = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(350, 11);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(37, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// btnInicio
			// 
			this->btnInicio->Location = System::Drawing::Point(197, 12);
			this->btnInicio->Name = L"btnInicio";
			this->btnInicio->Size = System::Drawing::Size(126, 23);
			this->btnInicio->TabIndex = 1;
			this->btnInicio->Text = L"Insertar al Inicio";
			this->btnInicio->UseVisualStyleBackColor = true;
			this->btnInicio->Click += gcnew System::EventHandler(this, &MyForm::btnInicio_Click);
			// 
			// btnFinal
			// 
			this->btnFinal->Location = System::Drawing::Point(199, 41);
			this->btnFinal->Name = L"btnFinal";
			this->btnFinal->Size = System::Drawing::Size(124, 23);
			this->btnFinal->TabIndex = 2;
			this->btnFinal->Text = L"Insertar al Final";
			this->btnFinal->UseVisualStyleBackColor = true;
			this->btnFinal->Click += gcnew System::EventHandler(this, &MyForm::btnFinal_Click);
			// 
			// btnPosicion
			// 
			this->btnPosicion->Location = System::Drawing::Point(420, 41);
			this->btnPosicion->Name = L"btnPosicion";
			this->btnPosicion->Size = System::Drawing::Size(119, 23);
			this->btnPosicion->TabIndex = 3;
			this->btnPosicion->Text = L"Insertar en Posición";
			this->btnPosicion->UseVisualStyleBackColor = true;
			this->btnPosicion->Click += gcnew System::EventHandler(this, &MyForm::btnPosicion_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(420, 11);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(119, 23);
			this->btnEliminar->TabIndex = 4;
			this->btnEliminar->Text = L"Eliminar en Posición";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &MyForm::btnEliminar_Click);
			// 
			// txtDato
			// 
			this->txtDato->Location = System::Drawing::Point(51, 14);
			this->txtDato->Name = L"txtDato";
			this->txtDato->Size = System::Drawing::Size(123, 20);
			this->txtDato->TabIndex = 5;
			// 
			// lblDato
			// 
			this->lblDato->AutoSize = true;
			this->lblDato->Location = System::Drawing::Point(12, 17);
			this->lblDato->Name = L"lblDato";
			this->lblDato->Size = System::Drawing::Size(33, 13);
			this->lblDato->TabIndex = 6;
			this->lblDato->Text = L"Dato:";
			// 
			// lblImprinir
			// 
			this->lblImprinir->AutoSize = true;
			this->lblImprinir->Location = System::Drawing::Point(12, 78);
			this->lblImprinir->Name = L"lblImprinir";
			this->lblImprinir->Size = System::Drawing::Size(10, 13);
			this->lblImprinir->TabIndex = 7;
			this->lblImprinir->Text = L" ";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Lista simple.", L"Lista simple con puntero al final.",
					L"Lista doble.", L"Lista doble con puntero al final.", L"Lista circular.", L"Lista circular con puntero al final.", L"Lista doble circular."
			});
			this->comboBox2->Location = System::Drawing::Point(639, 9);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(207, 21);
			this->comboBox2->TabIndex = 8;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(562, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Tipo de Lista:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 323);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->lblImprinir);
			this->Controls->Add(this->lblDato);
			this->Controls->Add(this->txtDato);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnPosicion);
			this->Controls->Add(this->btnFinal);
			this->Controls->Add(this->btnInicio);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void Imprimir_CLista_Enlazada()
			{
				String^ cadena = gcnew String(objCLista_Enlazada->toString().c_str());
			//	char *Cadena = const_cast<char*>(objCLista_Enlazada->toString().c_str());
				lblImprinir->Text = cadena;
			}


	private: System::Void btnInicio_Click(System::Object^  sender, System::EventArgs^  e) 
		{
					 if (txtDato->Text != "")
						 {	
							char* Dato = new char[100];
							sprintf(Dato, "%s", txtDato->Text);
							objCLista_Enlazada->Insertar_Inicio(Dato);
							objLista_SimplePF->Insertar_Inicio(Dato);
							objListaDoble->Insertar_Inicio(Dato);
							objListaDobPF->Insertar_Inicio(Dato);
							objListaCircular->Insertar_Inicio(Dato);
							objListaCirPF->Insertar_Inicio(Dato);
							objListaDobCirc->Insertar_Inicio(Dato);
							switch (selected)
							{
							case 0:
								//objCLista_Enlazada->Insertar_Inicio(Dato);
								objCLista_Enlazada->Draw_Lista(g);

							//	comboBox1->Items->Add(objCLista_Enlazada->numElementos);
								break;
							case 1:
								//objLista_SimplePF->Insertar_Inicio(Dato);
								objLista_SimplePF->Draw_Lista(g);

							//	comboBox1->Items->Add(objLista_SimplePF->numElementos);
								break;
							case 2:
								//objListaDoble->Insertar_Inicio(Dato);
								objListaDoble->Draw_List(g);
							//	comboBox1->Items->Add(objListaDoble->numElementos);
								break;
							case 3:
								//objListaDobPF->Insertar_Inicio(Dato);
								objListaDobPF->Draw_List(g);
							//	comboBox1->Items->Add(objListaDobPF->numElementos);
								break;
							case 4:
								//objListaCircular->Insertar_Inicio(Dato);
								objListaCircular->Draw_List(g);
							//	comboBox1->Items->Add(objListaCircular->numElementos);
								break;
							case 5:
								//objListaCirPF->Insertar_Inicio(Dato);
								objListaCirPF->Draw_List(g);
							//	comboBox1->Items->Add(objListaCirPF->numElementos);
								break;
							case 6:
								//objListaDobCirc->Insertar_Inicio(Dato);
								objListaDobCirc->Draw_List(g);
								//comboBox1->Items->Add(objListaDobCirc->numElementos);
								break;
							default:
								break;
							}
							comboBox1->Items->Add(objListaDobCirc->numElementos);
							txtDato->Focus();
							
						 }
					 else
						 MessageBox::Show("Debe ingresar por lo menos un caracter como dato");
		}

	private: System::Void btnFinal_Click(System::Object^  sender, System::EventArgs^  e)
		{
				 if (txtDato->Text != "")
					 {
						 char* Dato = new char[100];
						 sprintf(Dato, "%s", txtDato->Text);
						 objCLista_Enlazada->Insertar_Final(Dato);
						 objLista_SimplePF->Insertar_Final(Dato);
						 objListaDoble->Insertar_Final(Dato);
						 objListaDobPF->Insertar_Final(Dato);
						 objListaCircular->Insertar_Final(Dato);
						 objListaCirPF->Insertar_Final(Dato);
						 objListaDobCirc->Insertar_Final(Dato);
						 switch (selected)
						 {
						 case 0:
							 //objCLista_Enlazada->Insertar_Final(Dato);
							 objCLista_Enlazada->Draw_Lista(g);

						//	 comboBox1->Items->Add(objCLista_Enlazada->numElementos);
							 break;
						 case 1:
							// objLista_SimplePF->Insertar_Final(Dato);
							 objLista_SimplePF->Draw_Lista(g);

							 //comboBox1->Items->Add(objLista_SimplePF->numElementos);
							 break;
						 case 2:
							 //objListaDoble->Insertar_Final(Dato);
							 objListaDoble->Draw_List(g);
						//	 comboBox1->Items->Add(objListaDoble->numElementos);
							 break;
						 case 3:
							// objListaDobPF->Insertar_Final(Dato);
							 objListaDobPF->Draw_List(g);
						//	 comboBox1->Items->Add(objListaDobPF->numElementos);
							 break;
						 case 4:
							// objListaCircular->Insertar_Final(Dato);
							 objListaCircular->Draw_List(g);
						//	 comboBox1->Items->Add(objListaCircular->numElementos);
							 break;
						 case 5:
							// objListaCirPF->Insertar_Final(Dato);
							 objListaCirPF->Draw_List(g);
						//	 comboBox1->Items->Add(objListaCirPF->numElementos);
							 break;
						 case 6: 
							 //objListaDobCirc->Insertar_Final(Dato);
							 objListaDobCirc->Draw_List(g);
							 //comboBox1->Items->Add(objListaDobCirc->numElementos);
							 break;
						 default:
							 break;
						 }
						 comboBox1->Items->Add(objListaDobCirc->numElementos);
						 txtDato->Focus();
						 
					 }
				 else
					 MessageBox::Show("Debe ingresar por lo menos un caracter como dato");
		}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void btnEliminar_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBox1->SelectedIndex != -1) {
		
		objListaDobCirc->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
		objListaCirPF->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
		objListaCircular->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
		objListaDobPF->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
		objListaDoble->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
		objLista_SimplePF->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
		objCLista_Enlazada->Eliminar_Posicion(comboBox1->SelectedIndex + 1);

		switch (selected)
		{
		case 0:
			//objCLista_Enlazada->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objCLista_Enlazada->Draw_Lista(g);

			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objCLista_Enlazada->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
			//comboBox1->Items->Remove(objCLista_Enlazada->numElementos);
			break;
		case 1:
			//objLista_SimplePF->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objLista_SimplePF->Draw_Lista(g);

			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objLista_SimplePF->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
			break;
		case 2:
			//objListaDoble->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objListaDoble->Draw_List(g);
			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objListaDoble->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
		//	comboBox1->Items->Remove(objListaDoble->numElementos);
			break;
		case 3:
			//objListaDobPF->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objListaDobPF->Draw_List(g);
			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objListaDobPF->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
			break;
		case 4:
			//objListaCircular->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objListaCircular->Draw_List(g);
			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objListaCircular->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
			break;
		case 5:
			//objListaCirPF->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objListaCirPF->Draw_List(g);
			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objListaCirPF->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
			break;
		case 6:
			
			//objListaDobCirc->Eliminar_Posicion(comboBox1->SelectedIndex + 1);
			objListaDobCirc->Draw_List(g);
			/*comboBox1->Items->Clear();

			for (int i = 1; i <= objListaDobCirc->numElementos; i++)
			{
				comboBox1->Items->Add(i);
			}*/
			break;
		default:
			break;
		}
		txtDato->Focus();
		comboBox1->Items->Clear();

		for (int i = 1; i <= objListaDobCirc->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}
	}
}
private: System::Void btnPosicion_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBox1->SelectedIndex != -1) {
		char*Dato = new char[100];
		sprintf(Dato, "%s", txtDato->Text);
		
		objCLista_Enlazada->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
		objLista_SimplePF->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
		objListaDoble->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
		objListaDobPF->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
		objListaCircular->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
		objListaCirPF->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
		objListaDobCirc->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);

		switch (selected)
		{
		case 0:
			//objCLista_Enlazada->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objCLista_Enlazada->Draw_Lista(g);

			//comboBox1->Items->Add(objCLista_Enlazada->numElementos);
			break;
		case 1:
			//objLista_SimplePF->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objLista_SimplePF->Draw_Lista(g);

			//comboBox1->Items->Add(objLista_SimplePF->numElementos);
			break;
		case 2:
			//objListaDoble->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objListaDoble->Draw_List(g);
			//comboBox1->Items->Add(objListaDoble->numElementos);
			break;
		case 3:
			//objListaDobPF->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objListaDobPF->Draw_List(g);
			//comboBox1->Items->Add(objListaDobPF->numElementos);
			break;
		case 4:
			//objListaCircular->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objListaCircular->Draw_List(g);
			//comboBox1->Items->Add(objListaCircular->numElementos);
			break;
		case 5:
			//objListaCirPF->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objListaCirPF->Draw_List(g);
			//comboBox1->Items->Add(objListaCirPF->numElementos);
			break;
		case 6:
			//objListaDobCirc->Insertar_Posicion(Dato, comboBox1->SelectedIndex + 1);
			objListaDobCirc->Draw_List(g);
			//comboBox1->Items->Add(objListaDobCirc->numElementos);
			break;
		default:
			break;
		}
		comboBox1->Items->Add(objListaDobCirc->numElementos);
		txtDato->Focus();
	}
	else {
		MessageBox::Show("Seleccione una Posicion");
		txtDato->Focus();
	}
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	selected = comboBox2->SelectedIndex;

	switch (selected)
	{
	case 0://Lista Simplemente enlazada
		objCLista_Enlazada->Draw_Lista(g);
		/*comboBox1->Items->Clear();

		for (int i = 1; i <= objCLista_Enlazada->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		break;
	case 1://Lista Simplemente enlazada con puntero al final
		objLista_SimplePF->Draw_Lista(g);
		/*comboBox1->Items->Clear();

		for (int i = 1; i <= objLista_SimplePF->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		break;
	case 2://Lista doblemente enlazada
		objListaDoble->Draw_List(g);
		/*comboBox1->Items->Clear();

		for (int i = 1; i <= objListaDoble->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		break;
	case 3://Lista Doblemente enlazada con puntero al final
		objListaDobPF->Draw_List(g);
		/*comboBox1->Items->Clear();

		for (int i = 1; i <= objListaDobPF->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		
		break;
	case 4://Lista Circular
		objListaCircular->Draw_List(g);
		/*comboBox1->Items->Clear();
		for (int i = 1; i <= objListaCircular->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		break;
	case 5://Lista Circular con puntero al final
		objListaCirPF->Draw_List(g);
		/*comboBox1->Items->Clear();
		for (int i = 1; i <= objListaCirPF->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		break;
	case 6://Lista doble Circular
		objListaDobCirc->Draw_List(g);
		/*comboBox1->Items->Clear();
		for (int i = 1; i <= objListaDobCirc->numElementos; i++)
		{
			comboBox1->Items->Add(i);
		}*/
		break;
	default:
		break;
	}
	comboBox1->Items->Clear();
	for (int i = 1; i <= objListaDobCirc->numElementos; i++)
	{
		comboBox1->Items->Add(i);
	}
	txtDato->Focus();
}
};
}
