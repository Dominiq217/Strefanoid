#pragma once

namespace Stoper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o plansza
	/// </summary>
	public ref class plansza : public System::Windows::Forms::Form
	{
	public:
		plansza(void)
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
		~plansza()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblWyswietlacz;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pilka;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda wsparcia projektanta - nie nale¿y modyfikowaæ
		/// zawartoœæ tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(plansza::typeid));
			this->lblWyswietlacz = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pilka = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pilka))->BeginInit();
			this->SuspendLayout();
			// 
			// lblWyswietlacz
			// 
			this->lblWyswietlacz->AutoSize = true;
			this->lblWyswietlacz->Font = (gcnew System::Drawing::Font(L"Open Sans Light", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lblWyswietlacz->Location = System::Drawing::Point(45, 24);
			this->lblWyswietlacz->Name = L"lblWyswietlacz";
			this->lblWyswietlacz->Size = System::Drawing::Size(74, 87);
			this->lblWyswietlacz->TabIndex = 0;
			this->lblWyswietlacz->Text = L"0";
			this->lblWyswietlacz->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(208, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &plansza::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(208, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"STOP";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &plansza::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &plansza::timer1_Tick);
			// 
			// pilka
			// 
			this->pilka->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pilka.Image")));
			this->pilka->Location = System::Drawing::Point(1, 101);
			this->pilka->Name = L"pilka";
			this->pilka->Size = System::Drawing::Size(25, 25);
			this->pilka->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pilka->TabIndex = 3;
			this->pilka->TabStop = false;
			// 
			// plansza
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 127);
			this->Controls->Add(this->pilka);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblWyswietlacz);
			this->Name = L"plansza";
			this->Text = L"Stoper - animacja";
			this->Load += gcnew System::EventHandler(this, &plansza::plansza_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pilka))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		int licznik = 0;
		bool status = false;
		int x = 10;
#pragma endregion
	private: System::Void plansza_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;
		button2->Text = "STOP";
		status = false;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		licznik++;
		lblWyswietlacz->Text = Convert::ToString(licznik);
		pilka->Left += x;
		if (pilka->Left >= plansza::Width-40) x = -x;
		if (pilka->Left <= 5 ) x = -x;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
	if (status){
		licznik = 0;
		lblWyswietlacz->Text = "0";
		status = false;
		x = 10;
		pilka->Left = 0;
	}
	else{
		button2->Text = "RESET";
		status = true;
	}

}
};
}
