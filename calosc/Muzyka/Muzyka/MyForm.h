#pragma once

namespace Muzyka {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtPlik;
	private: System::Windows::Forms::Button^  btnPlik;
	protected:

	protected:

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  btnGraj;


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda wsparcia projektanta - nie nale¿y modyfikowaæ
		/// zawartoœæ tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtPlik = (gcnew System::Windows::Forms::TextBox());
			this->btnPlik = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnGraj = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtPlik
			// 
			this->txtPlik->Location = System::Drawing::Point(12, 28);
			this->txtPlik->Name = L"txtPlik";
			this->txtPlik->Size = System::Drawing::Size(489, 20);
			this->txtPlik->TabIndex = 0;
			// 
			// btnPlik
			// 
			this->btnPlik->Location = System::Drawing::Point(209, 54);
			this->btnPlik->Name = L"btnPlik";
			this->btnPlik->Size = System::Drawing::Size(75, 23);
			this->btnPlik->TabIndex = 1;
			this->btnPlik->Text = L"wybierz plik";
			this->btnPlik->UseVisualStyleBackColor = true;
			this->btnPlik->Click += gcnew System::EventHandler(this, &MyForm::btnPlik_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(58, 158);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Beep";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btnGraj
			// 
			this->btnGraj->Location = System::Drawing::Point(347, 158);
			this->btnGraj->Name = L"btnGraj";
			this->btnGraj->Size = System::Drawing::Size(75, 23);
			this->btnGraj->TabIndex = 3;
			this->btnGraj->Text = L"Odtwórz";
			this->btnGraj->UseVisualStyleBackColor = true;
			this->btnGraj->Click += gcnew System::EventHandler(this, &MyForm::btnGraj_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(513, 202);
			this->Controls->Add(this->btnGraj);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnPlik);
			this->Controls->Add(this->txtPlik);
			this->Name = L"MyForm";
			this->Text = L"DŸwiêki";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Console::Beep();
	}
	private: System::Void btnPlik_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ plik = gcnew OpenFileDialog;
		plik->Title = "Otwórz pliki audio";
		plik->Filter = "Pliki wav | *.wav";
		if (plik->ShowDialog() == Windows::Forms::DialogResult::OK){
			txtPlik->Text = plik->FileName;
		}
	}
private: System::Void btnGraj_Click(System::Object^  sender, System::EventArgs^  e) {
	try{
		System::Media::SoundPlayer^ graj = gcnew System::Media::SoundPlayer();
		graj->SoundLocation = txtPlik->Text;
		graj->Load();
		graj->Play();
	}
	catch (...)
	{
		// 
	}
}
};
}
