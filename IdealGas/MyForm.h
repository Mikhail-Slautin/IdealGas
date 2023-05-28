#pragma once
#define _USE_MATH_DEFINES
#include<iostream>
#include"RealGas.h"

namespace IdealGas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		int w, h,XX,YY,n;
		double a,r,t,m,E;
		bool istrue;
		double k;
		double *x, *y, *z;
		double cos_p_4;
		Graphics^ gr;
		BufferedGraphics^ buffergr;
		RealGas* gas;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::CheckBox^ checkBox1;
		   BufferedGraphicsContext^ buffergrcon;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Info;
			this->panel1->ForeColor = System::Drawing::SystemColors::Info;
			this->panel1->Location = System::Drawing::Point(299, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(508, 490);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(183, 93);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"50";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(161, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"a";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(37, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(183, 135);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"100";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(183, 191);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(161, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(161, 196);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"r";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(183, 288);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 9;
			this->textBox5->Text = L"1";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(183, 328);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 10;
			this->textBox6->Text = L"300";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(164, 293);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"m";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(164, 331);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"E";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(167, 33);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(46, 369);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"a";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(46, 421);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(16, 17);
			this->label8->TabIndex = 15;
			this->label8->Text = L"a";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(46, 485);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(16, 17);
			this->label9->TabIndex = 16;
			this->label9->Text = L"a";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(37, 135);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(98, 21);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 562);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		w = panel1->Width-1;
		h = panel1->Height - 1;
		a = Convert::ToDouble(textBox1->Text);
		n = Convert::ToDouble(textBox2->Text);
		r = Convert::ToDouble(textBox3->Text);
		t =0.001;
		m = Convert::ToDouble(textBox5->Text);
		E = Convert::ToDouble(textBox6->Text);
		if (checkBox1->Checked)
		{
			E = 1.5 * n * 273.15 / 119.8;
			a = pow(n * 224.136 / 6.022045, 1. / 3.) * 10. / 3.405;
			this->textBox6->Text = Convert::ToString(E);
			this->textBox1->Text = Convert::ToString(a);
		}
		x = new double[n];
		y = new double[n];
		z = new double[n];
		cos_p_4 = cos(M_PI / 4.);
		k = w / (a + a * cos_p_4);
		gr = panel1->CreateGraphics();
		this->buffergrcon = BufferedGraphicsManager::Current;
		this->buffergrcon->MaximumBuffer = System::Drawing::Size(w + 1, h + 1);
		this->buffergr = buffergrcon->Allocate(gr, Rectangle(0, 0, w + 1, h + 1));
		this->buffergr->Graphics->Clear(System::Drawing::SystemColors::Info);
		gas = new RealGas(n, t, a, r, m, E);
		istrue = false;
		gas->SetInit();
		DrawFunc();
		istrue = true;
		while (istrue)
		{
			Application::DoEvents();
			gas->DoOneStep();
			label7->Text=Convert::ToString(gas->E);
			label8->Text = Convert::ToString(gas->Ekin);
			label9->Text = Convert::ToString(gas->Epot);
			DrawFunc();

			
		}
	}
		   void DrawFunc()
		   {
			   array<float>^ mypat = gcnew array<float>(2);
			   mypat[0] = 5;
			   mypat[1] = 5;
			   array<Point>^ p=gcnew array<Point>(4);
			   p[0].X = w-a*k-a*cos_p_4*k+1;
			   p[0].Y = h;
			   p[1].X = w-a * k+1;
			   p[1].Y = h-a*cos_p_4 * k;
			   p[2].X = w-a * k+1;
			   p[2].Y = h-a * k -a*cos_p_4 * k;
			   p[3].X = w - a * k - a * cos_p_4 * k+1;
			   p[3].Y = h-a * k;
			   Pen^ pen = gcnew Pen(Color::Black);
			   Brush^ br=gcnew System::Drawing::Drawing2D::LinearGradientBrush(p[0],p[2],Color::White,Color::Aquamarine);
			   buffergr->Graphics->FillPolygon(br, p);
			   buffergr->Graphics->DrawLine(pen, p[0], p[3]);

			   pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Custom;
			   pen->DashPattern = mypat;
			   p[0].X = w - a * k - a * cos_p_4 * k;
			   p[0].Y = h;
			   p[1].X = w-a*cos_p_4*k;
			   p[1].Y = h ;
			   p[2].X = w ;
			   p[2].Y = h  - a * cos_p_4 * k;
			   p[3].X = w - a * k ;
			   p[3].Y = h - a *cos_p_4* k;
			   Brush^ br1 = gcnew System::Drawing::Drawing2D::LinearGradientBrush(p[0], p[2], Color::White, Color::Aquamarine);
			   buffergr->Graphics->FillPolygon(br1, p);
			   buffergr->Graphics->DrawLine(pen, p[2], p[3]);
			   buffergr->Graphics->DrawLine(pen, p[0], p[3]);
			   pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
			   buffergr->Graphics->DrawLine(pen, p[0], p[1]);


			  
			   p[0].X = w - a * k ;
			   p[0].Y = h- a * cos_p_4 * k;
			   p[1].X = w ;
			   p[1].Y = h - a * cos_p_4 * k;
			   p[2].X = w;
			   p[2].Y = h - a*k-a * cos_p_4 * k;
			   p[3].X = w - a * k;
			   p[3].Y = h - a * k - a * cos_p_4 * k;
			   Brush^ br2 = gcnew System::Drawing::Drawing2D::LinearGradientBrush(p[0], p[2], Color::White, Color::Aquamarine);
			   buffergr->Graphics->FillPolygon(br2, p);
			   pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Custom;
			   pen->DashPattern = mypat;
			   buffergr->Graphics->DrawLine(pen, p[0], p[3]);


			   p[0].X = w - a * cos_p_4 * k;
			   p[0].Y = h ;
			   p[1].X = w;
			   p[1].Y = h - a * cos_p_4 * k;
			   p[2].X = w;
			   p[2].Y = h - a * k - a * cos_p_4 * k;
			   p[3].X = w - a * cos_p_4 * k;
			   p[3].Y = h - a * k ;
			   Brush^ br3 = gcnew System::Drawing::Drawing2D::LinearGradientBrush(p[0], p[2], Color::White, Color::Aquamarine);
			   buffergr->Graphics->FillPolygon(br3, p);
			   pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
			   buffergr->Graphics->DrawLine(pen, p[0], p[1]);
			   buffergr->Graphics->DrawLine(pen, p[1], p[2]);
			   buffergr->Graphics->DrawLine(pen, p[2], p[3]);
			   buffergr->Graphics->DrawLine(pen, p[0], p[3]);

			   p[0].X = w -a*k-a * cos_p_4 * k;
			   p[0].Y = h-a*k;
			   p[1].X = w - a * cos_p_4 * k;
			   p[1].Y = h - a * k;
			   p[2].X = w;
			   p[2].Y = h - a * k - a * cos_p_4 * k;
			   p[3].X = w - a * k;
			   p[3].Y = h - a * k - a * cos_p_4 * k;
			   Brush^ br4 = gcnew System::Drawing::Drawing2D::LinearGradientBrush(p[0], p[2], Color::White, Color::Aquamarine);
			   buffergr->Graphics->FillPolygon(br4, p);
			   pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
			   buffergr->Graphics->DrawLine(pen, p[0], p[1]);
			   buffergr->Graphics->DrawLine(pen, p[1], p[2]);
			   buffergr->Graphics->DrawLine(pen, p[2], p[3]);
			   buffergr->Graphics->DrawLine(pen, p[0], p[3]);


			   p[0].X = w - a * k - a * cos_p_4 * k;
			   p[0].Y = h ;
			   p[1].X = w - a * cos_p_4 * k;
			   p[1].Y = h ;
			   p[2].X = w - a * cos_p_4 * k;
			   p[2].Y = h - a * k ;
			   p[3].X = w - a * k-a*cos_p_4*k;
			   p[3].Y = h - a * k ;
			   Brush^ br5 = gcnew System::Drawing::Drawing2D::LinearGradientBrush(p[0], p[2], Color::White, Color::Aquamarine);
			   //buffergr->Graphics->FillPolygon(br5, p);
			   Brush^ br6 = gcnew SolidBrush(Color::Brown);
			   for (int i = 0;i < n;i++)
			   {
				   XX = (gas->p[i].x + gas->p[i].z * cos_p_4) * k;
				   YY = h - (gas->p[i].y + gas->p[i].z *cos_p_4) * k;
				   buffergr->Graphics->FillEllipse(br6, XX, YY, r*k, r*k );
			   }
			   buffergr->Render();
			   delete br;
			   delete br1;
			   delete br2;
			   delete br3;
			   delete br4;
			   delete br5;
			   delete br6;
			   delete pen;
		   }
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	istrue = false;
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

}
};
}
