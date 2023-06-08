#pragma once

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace OOPLab11 {


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonFill;
	private: System::Windows::Forms::Label^ labelRows;
	protected:


	private: System::Windows::Forms::TextBox^ textBoxRows;
	private: System::Windows::Forms::Label^ labelColumns;






	private: System::Windows::Forms::TextBox^ textBoxColumns;
	private: System::Windows::Forms::Button^ buttonSetVal;


	private: System::Windows::Forms::TextBox^ textBoxI;
	private: System::Windows::Forms::Label^ labelI;
	private: System::Windows::Forms::Label^ labelJ;




	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonGetVal;





	private: System::Windows::Forms::TextBox^ textBoxNewVal;
	private: System::Windows::Forms::Label^ labelNewVal;


	private: System::Windows::Forms::TextBox^ textBoxJ;
	private: System::Windows::Forms::Label^ labelValIs;









	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::MenuStrip^ menuStrip;


	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ writeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fillToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ getValueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setValueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ ErrorLabel;








	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonFill = (gcnew System::Windows::Forms::Button());
			this->labelRows = (gcnew System::Windows::Forms::Label());
			this->textBoxRows = (gcnew System::Windows::Forms::TextBox());
			this->labelColumns = (gcnew System::Windows::Forms::Label());
			this->textBoxColumns = (gcnew System::Windows::Forms::TextBox());
			this->buttonSetVal = (gcnew System::Windows::Forms::Button());
			this->textBoxI = (gcnew System::Windows::Forms::TextBox());
			this->labelI = (gcnew System::Windows::Forms::Label());
			this->labelJ = (gcnew System::Windows::Forms::Label());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonGetVal = (gcnew System::Windows::Forms::Button());
			this->textBoxNewVal = (gcnew System::Windows::Forms::TextBox());
			this->labelNewVal = (gcnew System::Windows::Forms::Label());
			this->textBoxJ = (gcnew System::Windows::Forms::TextBox());
			this->labelValIs = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ErrorLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->writeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonFill
			// 
			this->buttonFill->Location = System::Drawing::Point(88, 173);
			this->buttonFill->Name = L"buttonFill";
			this->buttonFill->Size = System::Drawing::Size(100, 40);
			this->buttonFill->TabIndex = 0;
			this->buttonFill->Text = L"Fill";
			this->buttonFill->UseVisualStyleBackColor = true;
			this->buttonFill->Click += gcnew System::EventHandler(this, &MyForm::buttonFill_Click);
			// 
			// labelRows
			// 
			this->labelRows->AutoSize = true;
			this->labelRows->Location = System::Drawing::Point(116, 97);
			this->labelRows->Name = L"labelRows";
			this->labelRows->Size = System::Drawing::Size(41, 16);
			this->labelRows->TabIndex = 1;
			this->labelRows->Text = L"Rows";
			this->labelRows->Click += gcnew System::EventHandler(this, &MyForm::labelRows_Click);
			// 
			// textBoxRows
			// 
			this->textBoxRows->Location = System::Drawing::Point(88, 127);
			this->textBoxRows->Name = L"textBoxRows";
			this->textBoxRows->Size = System::Drawing::Size(100, 22);
			this->textBoxRows->TabIndex = 2;
			this->textBoxRows->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxRows_TextChanged);
			// 
			// labelColumns
			// 
			this->labelColumns->AutoSize = true;
			this->labelColumns->Location = System::Drawing::Point(261, 97);
			this->labelColumns->Name = L"labelColumns";
			this->labelColumns->Size = System::Drawing::Size(59, 16);
			this->labelColumns->TabIndex = 5;
			this->labelColumns->Text = L"Columns";
			// 
			// textBoxColumns
			// 
			this->textBoxColumns->Location = System::Drawing::Point(240, 127);
			this->textBoxColumns->Name = L"textBoxColumns";
			this->textBoxColumns->Size = System::Drawing::Size(100, 22);
			this->textBoxColumns->TabIndex = 6;
			this->textBoxColumns->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxColumns_TextChanged);
			// 
			// buttonSetVal
			// 
			this->buttonSetVal->Location = System::Drawing::Point(88, 333);
			this->buttonSetVal->Name = L"buttonSetVal";
			this->buttonSetVal->Size = System::Drawing::Size(100, 40);
			this->buttonSetVal->TabIndex = 7;
			this->buttonSetVal->Text = L"Set value";
			this->buttonSetVal->UseVisualStyleBackColor = true;
			this->buttonSetVal->Click += gcnew System::EventHandler(this, &MyForm::buttonSetVal_Click);
			// 
			// textBoxI
			// 
			this->textBoxI->Location = System::Drawing::Point(123, 242);
			this->textBoxI->Name = L"textBoxI";
			this->textBoxI->Size = System::Drawing::Size(38, 22);
			this->textBoxI->TabIndex = 8;
			this->textBoxI->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxI_TextChanged);
			// 
			// labelI
			// 
			this->labelI->AutoSize = true;
			this->labelI->Location = System::Drawing::Point(88, 245);
			this->labelI->Name = L"labelI";
			this->labelI->Size = System::Drawing::Size(20, 16);
			this->labelI->TabIndex = 10;
			this->labelI->Text = L"i =";
			// 
			// labelJ
			// 
			this->labelJ->AutoSize = true;
			this->labelJ->Location = System::Drawing::Point(185, 245);
			this->labelJ->Name = L"labelJ";
			this->labelJ->Size = System::Drawing::Size(20, 16);
			this->labelJ->TabIndex = 11;
			this->labelJ->Text = L"j =";
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(240, 173);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(100, 40);
			this->buttonClear->TabIndex = 12;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MyForm::buttonClear_Click);
			// 
			// buttonGetVal
			// 
			this->buttonGetVal->Location = System::Drawing::Point(240, 333);
			this->buttonGetVal->Name = L"buttonGetVal";
			this->buttonGetVal->Size = System::Drawing::Size(100, 40);
			this->buttonGetVal->TabIndex = 13;
			this->buttonGetVal->Text = L"Get value";
			this->buttonGetVal->UseVisualStyleBackColor = true;
			this->buttonGetVal->Click += gcnew System::EventHandler(this, &MyForm::buttonGetVal_Click);
			// 
			// textBoxNewVal
			// 
			this->textBoxNewVal->Location = System::Drawing::Point(206, 294);
			this->textBoxNewVal->Name = L"textBoxNewVal";
			this->textBoxNewVal->Size = System::Drawing::Size(134, 22);
			this->textBoxNewVal->TabIndex = 14;
			this->textBoxNewVal->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxNewVal_TextChanged);
			// 
			// labelNewVal
			// 
			this->labelNewVal->AutoSize = true;
			this->labelNewVal->Location = System::Drawing::Point(106, 297);
			this->labelNewVal->Name = L"labelNewVal";
			this->labelNewVal->Size = System::Drawing::Size(67, 16);
			this->labelNewVal->TabIndex = 15;
			this->labelNewVal->Text = L"new value";
			this->labelNewVal->Click += gcnew System::EventHandler(this, &MyForm::labelNewVal_Click);
			// 
			// textBoxJ
			// 
			this->textBoxJ->Location = System::Drawing::Point(215, 242);
			this->textBoxJ->Name = L"textBoxJ";
			this->textBoxJ->Size = System::Drawing::Size(38, 22);
			this->textBoxJ->TabIndex = 16;
			this->textBoxJ->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxJ_TextChanged);
			// 
			// labelValIs
			// 
			this->labelValIs->AutoSize = true;
			this->labelValIs->Location = System::Drawing::Point(273, 245);
			this->labelValIs->Name = L"labelValIs";
			this->labelValIs->Size = System::Drawing::Size(0, 16);
			this->labelValIs->TabIndex = 17;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->ErrorLabel);
			this->panel1->Controls->Add(this->labelValIs);
			this->panel1->Controls->Add(this->buttonSetVal);
			this->panel1->Controls->Add(this->textBoxJ);
			this->panel1->Controls->Add(this->buttonFill);
			this->panel1->Controls->Add(this->labelNewVal);
			this->panel1->Controls->Add(this->labelRows);
			this->panel1->Controls->Add(this->textBoxNewVal);
			this->panel1->Controls->Add(this->textBoxRows);
			this->panel1->Controls->Add(this->buttonGetVal);
			this->panel1->Controls->Add(this->labelColumns);
			this->panel1->Controls->Add(this->buttonClear);
			this->panel1->Controls->Add(this->textBoxColumns);
			this->panel1->Controls->Add(this->labelJ);
			this->panel1->Controls->Add(this->textBoxI);
			this->panel1->Controls->Add(this->labelI);
			this->panel1->Location = System::Drawing::Point(914, 43);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(454, 605);
			this->panel1->TabIndex = 18;
			// 
			// ErrorLabel
			// 
			this->ErrorLabel->AutoSize = true;
			this->ErrorLabel->Location = System::Drawing::Point(212, 413);
			this->ErrorLabel->Name = L"ErrorLabel";
			this->ErrorLabel->Size = System::Drawing::Size(0, 16);
			this->ErrorLabel->TabIndex = 23;
			this->ErrorLabel->Click += gcnew System::EventHandler(this, &MyForm::ErrorLabel_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->tableToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(1398, 30);
			this->menuStrip->TabIndex = 20;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->readToolStripMenuItem,
					this->writeToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 26);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fileToolStripMenuItem_Click_1);
			// 
			// readToolStripMenuItem
			// 
			this->readToolStripMenuItem->Name = L"readToolStripMenuItem";
			this->readToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->readToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->readToolStripMenuItem->Text = L"Read";
			this->readToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::readToolStripMenuItem_Click);
			// 
			// writeToolStripMenuItem
			// 
			this->writeToolStripMenuItem->Name = L"writeToolStripMenuItem";
			this->writeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->writeToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->writeToolStripMenuItem->Text = L"Write";
			this->writeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::writeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// tableToolStripMenuItem
			// 
			this->tableToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fillToolStripMenuItem,
					this->getValueToolStripMenuItem, this->setValueToolStripMenuItem, this->clearToolStripMenuItem
			});
			this->tableToolStripMenuItem->Name = L"tableToolStripMenuItem";
			this->tableToolStripMenuItem->Size = System::Drawing::Size(58, 26);
			this->tableToolStripMenuItem->Text = L"Table";
			// 
			// fillToolStripMenuItem
			// 
			this->fillToolStripMenuItem->Name = L"fillToolStripMenuItem";
			this->fillToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->fillToolStripMenuItem->Text = L"Fill";
			this->fillToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fillToolStripMenuItem_Click);
			// 
			// getValueToolStripMenuItem
			// 
			this->getValueToolStripMenuItem->Name = L"getValueToolStripMenuItem";
			this->getValueToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->getValueToolStripMenuItem->Text = L"Get value";
			this->getValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::getValueToolStripMenuItem_Click);
			// 
			// setValueToolStripMenuItem
			// 
			this->setValueToolStripMenuItem->Name = L"setValueToolStripMenuItem";
			this->setValueToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->setValueToolStripMenuItem->Text = L"Set value";
			this->setValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::setValueToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 26);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 2;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel->Location = System::Drawing::Point(154, 70);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 2;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel->Size = System::Drawing::Size(499, 451);
			this->tableLayoutPanel->TabIndex = 21;
			this->tableLayoutPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel_Paint);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->tableLayoutPanel);
			this->panel2->Location = System::Drawing::Point(12, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(879, 605);
			this->panel2->TabIndex = 22;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1398, 678);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->menuStrip);
			this->Controls->Add(this->panel1);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"CTable";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonFill_Click(System::Object^ sender, System::EventArgs^ e) {
		int rows = 0, columns = 0;

		if (textBoxRows->Text == "" || textBoxColumns->Text == "") {
			ErrorLabel->Text = "Set row and cols number first!";
			return;
		}

		ErrorLabel->Text = "";

		if (Int32::TryParse(textBoxRows->Text, rows) && Int32::TryParse(textBoxColumns->Text, columns)) {
			tableLayoutPanel->Controls->Clear();

			tableLayoutPanel->RowCount = rows;
			tableLayoutPanel->ColumnCount = columns;

			tableLayoutPanel->ColumnStyles->Clear();
			for (int i = 0; i < columns; ++i) {
				tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
			}

			for (int row = 0; row < rows; ++row) {
				for (int column = 0; column < columns; ++column) {
					Label^ cell = gcnew Label();

					cell->Margin = System::Windows::Forms::Padding(0);
					tableLayoutPanel->Padding = System::Windows::Forms::Padding(0);
					cell->Font = gcnew System::Drawing::Font(cell->Font->FontFamily, cell->Font->Size + 9);
					
					if (((column >= columns - row - 1) && row < rows/2) || (row <= column && column >= columns/2 && row >= rows/2)) {
						cell->Text = "0";
					}
					else {
						cell->Text = "1";
					}

					tableLayoutPanel->Controls->Add(cell, column, row);
				}
			}
		}
		else
		{
			ErrorLabel->Text = "Error creating the table!";
		}
		
		int cellWidth = tableLayoutPanel->Width / columns;
		int cellHeight = tableLayoutPanel->Height / rows;

		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				Control^ cell = tableLayoutPanel->GetControlFromPosition(column, row);
				if (cell != nullptr) {
					cell->Width = cellWidth;
					cell->Height = cellHeight;
				}
			}
		}
}
private: System::Void labelRows_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void buttonSetVal_Click(System::Object^ sender, System::EventArgs^ e) {
	int i, j;

	ErrorLabel->Text = "";

	if (Int32::TryParse(textBoxI->Text, i) && Int32::TryParse(textBoxJ->Text, j)) {
		if (i < 0 || i >= tableLayoutPanel->RowCount || j < 0 || j >= tableLayoutPanel->ColumnCount) {
			textBoxNewVal->Text = "";
			ErrorLabel->Text = "Wrong index!";
			textBoxI->Text = "";
			textBoxJ->Text = "";
			textBoxNewVal->Text = "";
			return;
		}
		Control^ cell = tableLayoutPanel->GetControlFromPosition(j, i);
		if (cell != nullptr && cell->GetType() == Label::typeid) {
			cell->Text = textBoxNewVal->Text;
			textBoxNewVal->Text = "";
			ErrorLabel->Text = "";
			textBoxI->Text = "";
			textBoxJ->Text = "";
			textBoxNewVal->Text = "";
		}
	}
	else
	{
		ErrorLabel->Text = "Unexpected error.";
	}

}
private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanel->Controls->Clear();
	tableLayoutPanel->RowCount = 0;
	tableLayoutPanel->ColumnCount = 0;

	textBoxRows->Text = "";
	textBoxColumns->Text = "";
	textBoxI->Text = "";
	textBoxJ->Text = "";
	textBoxNewVal->Text = "";
}
private: System::Void labelNewVal_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void getToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void textBoxColumns_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxRows_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxI_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void fileToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxJ_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxNewVal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonGetVal_Click(System::Object^ sender, System::EventArgs^ e) {
	int i, j;

	ErrorLabel->Text = "";

	if (Int32::TryParse(textBoxI->Text, i) && Int32::TryParse(textBoxJ->Text, j)) {
		if (i < 0 || i >= tableLayoutPanel->RowCount || j < 0 || j >= tableLayoutPanel->ColumnCount) {
			labelValIs->Text = "";
			ErrorLabel->Text = "Wrong index!";
			textBoxI->Text = "";
			textBoxJ->Text = "";
			return;
		}
		Control^ cell = tableLayoutPanel->GetControlFromPosition(j, i);
		Label^ label = dynamic_cast<Label^>(cell);
		labelValIs->Text = "value is: " + label->Text;
		ErrorLabel->Text = "";
		textBoxI->Text = "";
		textBoxJ->Text = "";
	}
	else
	{
		ErrorLabel->Text = "Unexpected error.";
	}
}
private: System::Void ErrorLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void readToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ErrorLabel->Text = "";

	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

	openFileDialog->InitialDirectory = "D:\\repos\\univ\\OOPLab11";

	openFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ selectedFileName = openFileDialog->FileName;
		
		StreamReader^ reader = gcnew StreamReader(selectedFileName);

		String^ line = reader->ReadLine();
		
		array<String^>^ tableSize = line->Split(' ');

		int rows = Convert::ToInt32(tableSize[0]);
		int columns = Convert::ToInt32(tableSize[1]);

		tableLayoutPanel->RowCount = rows;
		tableLayoutPanel->ColumnCount = columns;
	
		reader->ReadLine();

		tableLayoutPanel->ColumnStyles->Clear();
		for (int i = 0; i < columns; ++i) {
			tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
		}

		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				Label^ cell = gcnew Label();

				cell->Margin = System::Windows::Forms::Padding(0);
				tableLayoutPanel->Padding = System::Windows::Forms::Padding(0);
				cell->Font = gcnew System::Drawing::Font(cell->Font->FontFamily, cell->Font->Size + 10);

				tableLayoutPanel->Controls->Add(cell, column, row);
			}
		}

		array<String^>^ numbers;

		int row = 0;
		while ((line = reader->ReadLine()) != nullptr) {
			numbers = line->Split(' ');
			for (int column = 0; column < columns; ++column) {
				Control^ cell = tableLayoutPanel->GetControlFromPosition(column, row);
				cell->Text = numbers[column];
			}
			++row;
		}

		int cellWidth = tableLayoutPanel->Width / columns;
		int cellHeight = tableLayoutPanel->Height / rows;

		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				Control^ cell = tableLayoutPanel->GetControlFromPosition(column, row);
				if (cell != nullptr) {
					cell->Width = cellWidth;
					cell->Height = cellHeight;
				}
			}
		}

		reader->Close();

	}
	else {
		ErrorLabel->Text = "Unexpected error.";
	}

}
private: System::Void writeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ErrorLabel->Text = "";

	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

	openFileDialog->InitialDirectory = "D:\\repos\\univ\\OOPLab11";

	openFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ selectedFileName = openFileDialog->FileName;

		StreamWriter^ writer = gcnew StreamWriter(selectedFileName);

		int rows = tableLayoutPanel->RowCount;
		int columns = tableLayoutPanel->ColumnCount;

		writer->Write(rows + " ");
		writer->Write(columns + "");
		writer->WriteLine();
		writer->WriteLine();

		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				Control^ cell = tableLayoutPanel->GetControlFromPosition(column, row);
				if (cell != nullptr) {
					String^ cellText = cell->Text;

					writer->Write(cellText);

					if (column < columns - 1) {
						writer->Write(" ");
					}
					else {
						writer->WriteLine();
					}
				}
			}
		}

		writer->Close();
	}
	else {
		ErrorLabel->Text = "Unexpected error.";
	}
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void fillToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int rows = 0, columns = 0;

	if (textBoxRows->Text == "" || textBoxColumns->Text == "") {
		ErrorLabel->Text = "Set row and cols number!";
		return;
	}

	ErrorLabel->Text = "";

	if (Int32::TryParse(textBoxRows->Text, rows) && Int32::TryParse(textBoxColumns->Text, columns)) {
		tableLayoutPanel->Controls->Clear();

		tableLayoutPanel->RowCount = rows;
		tableLayoutPanel->ColumnCount = columns;

		tableLayoutPanel->ColumnStyles->Clear();
		for (int i = 0; i < columns; ++i) {
			tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
		}

		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				Label^ cell = gcnew Label();

				cell->Margin = System::Windows::Forms::Padding(0);
				tableLayoutPanel->Padding = System::Windows::Forms::Padding(0);
				cell->Font = gcnew System::Drawing::Font(cell->Font->FontFamily, cell->Font->Size + 9);

				if (column % 2 == 0) {
					cell->Text = "1";
				}
				else {
					cell->Text = "0";
				}

				tableLayoutPanel->Controls->Add(cell, column, row);
			}
		}
	}
	else
	{
		ErrorLabel->Text = "Error creating the table!";
	}

	int cellWidth = tableLayoutPanel->Width / columns;
	int cellHeight = tableLayoutPanel->Height / rows;

	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			Control^ cell = tableLayoutPanel->GetControlFromPosition(column, row);
			if (cell != nullptr) {
				cell->Width = cellWidth;
				cell->Height = cellHeight;
			}
		}
	}
}
private: System::Void getValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int i, j;

	ErrorLabel->Text = "";

	if (Int32::TryParse(textBoxI->Text, i) && Int32::TryParse(textBoxJ->Text, j)) {
		if (i < 0 || i >= tableLayoutPanel->RowCount || j < 0 || j >= tableLayoutPanel->ColumnCount) {
			labelValIs->Text = "";
			ErrorLabel->Text = "Wrong index!";
			textBoxI->Text = "";
			textBoxJ->Text = "";
			return;
		}
		Control^ cell = tableLayoutPanel->GetControlFromPosition(j, i);
		Label^ label = dynamic_cast<Label^>(cell);
		labelValIs->Text = "value is: " + label->Text;
		ErrorLabel->Text = "";
		textBoxI->Text = "";
		textBoxJ->Text = "";
	}
	else
	{
		ErrorLabel->Text = "Unexpected error.";
	}
}
private: System::Void setValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int i, j;

	ErrorLabel->Text = "";

	if (Int32::TryParse(textBoxI->Text, i) && Int32::TryParse(textBoxJ->Text, j)) {
		if (i < 0 || i >= tableLayoutPanel->RowCount || j < 0 || j >= tableLayoutPanel->ColumnCount) {
			textBoxNewVal->Text = "";
			ErrorLabel->Text = "Wrong index!";
			textBoxI->Text = "";
			textBoxJ->Text = "";
			textBoxNewVal->Text = "";
			return;
		}
		Control^ cell = tableLayoutPanel->GetControlFromPosition(j, i);
		if (cell != nullptr && cell->GetType() == Label::typeid) {
			cell->Text = textBoxNewVal->Text;
			textBoxNewVal->Text = "";
			ErrorLabel->Text = "";
			textBoxI->Text = "";
			textBoxJ->Text = "";
			textBoxNewVal->Text = "";
		}
	}
	else
	{
		ErrorLabel->Text = "Unexpected error.";
	}

}
private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanel->Controls->Clear();
	tableLayoutPanel->RowCount = 0;
	tableLayoutPanel->ColumnCount = 0;

	textBoxRows->Text = "";
	textBoxColumns->Text = "";
	textBoxI->Text = "";
	textBoxJ->Text = "";
	textBoxNewVal->Text = "";
}
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ message = "Full documentation is provided here:\nhttps://www.youtube.com/watch?v=dQw4w9WgXcQ&t=43s";
	MessageBox::Show(message, "Help", MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1, MessageBoxOptions::DefaultDesktopOnly);
}
private: System::Void labelValIS_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}