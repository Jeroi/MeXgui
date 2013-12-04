#include "MeGUI.core.gui.AutoUpdateServerConfigWindow.h"

//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Collections::Generic;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Windows::Forms;
namespace MeGUI
{
	namespace core
	{
		namespace gui
		{

			AutoUpdateServerConfigWindow::AutoUpdateServerConfigWindow()
			{
				InitializeInstanceFields();
				InitializeComponent();
			}

			void AutoUpdateServerConfigWindow::addServerButton_Click(object *sender, EventArgs *e)
			{
				std::string serverName = InputBox::Show("Please enter the server address", "Please enter the server address", "http://yourserver.org/path/to/update/folder/");
				if (serverName == "")
					return;
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
				serverName = serverName.Trim();
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'EndsWith' method:
				if (!serverName.EndsWith("/"))
					serverName += "/";

				if (serverList->Items->Contains(serverName))
				{
					MessageBox::Show("Server already listed. Adding nothing", "Server already listed", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'StartsWith' method:
				if (!serverName.StartsWith("http://"))
				{
					MessageBox::Show("Only http servers are supported", "Server not http", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				UpdateWindow *oUpdateWindow = new UpdateWindow(MainForm::Instance, true);
				if (oUpdateWindow->GetUpdateXML(serverName) != UpdateWindow::Successful)
				{
					if (MessageBox::Show("The server or the XML file is not available.\r\nShould it be added nevertheless?", "No connection to server", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes)
						return;
				}
				serverList->Items->Add(serverName);
			}

			void AutoUpdateServerConfigWindow::removeSelectedServersButton_Click(object *sender, EventArgs *e)
			{
				object items[serverList->SelectedItems->Count];
				serverList->SelectedItems->CopyTo(items, 0);
				for (object::const_iterator o = items->begin(); o != items->end(); ++o)
				{
					serverList->Items->Remove(*o);
				}
			}

			const int &AutoUpdateServerConfigWindow::getServerListIndex() const
			{
				return subList->SelectedIndex;
			}

			void AutoUpdateServerConfigWindow::setServerListIndex(const int &value)
			{
				subList->SelectedIndex = value;
			}

			const std::string &*AutoUpdateServerConfigWindow::getServerList() const
			{
				subList_SelectedIndexChanged(0, 0);
				return serverLists;
			}

			void AutoUpdateServerConfigWindow::setServerList(const std::string &value[][])
			{
				serverLists = value;
				oldIndex = -1;
				subList->Items->Clear();

				for (std::string[][]::const_iterator sub = value->begin(); sub != value->end(); ++sub)
					subList->Items->Add(*sub[0]);

				subList_SelectedIndexChanged(0, 0);
			}

			const std::string &AutoUpdateServerConfigWindow::getlittleServerList() const
			{
				std::vector<std::string> list = std::vector<std::string>();
				list.push_back(oldTitle);
				for (unknown::const_iterator o = serverList->Items.begin(); o != serverList->Items.end(); ++o)
					list.push_back(*o);
				return list.ToArray();
			}

			void AutoUpdateServerConfigWindow::setlittleServerList(const std::string &value[])
			{
				oldTitle = value[0];
				serverList->Items->Clear();
				serverList->Items->AddRange(value);
				serverList->Items->RemoveAt(0);
			}

			void AutoUpdateServerConfigWindow::subList_SelectedIndexChanged(object *sender, EventArgs *e)
			{
				if (oldIndex > -1)
					serverLists[oldIndex] = getlittleServerList();
				oldIndex = subList->SelectedIndex;
				if (oldIndex > -1)
					setlittleServerList(serverLists[subList->SelectedIndex]);
				if (subList->SelectedIndex < 2)
					addServerButton->Enabled = removeSelectedServersButton->Enabled = false;
				else
					addServerButton->Enabled = removeSelectedServersButton->Enabled = true;
			}

			void AutoUpdateServerConfigWindow::Dispose(bool disposing)
			{
				if (disposing && (components != 0))
				{
					delete components;
				}
				System::Windows::Forms::Form::Dispose(disposing);
			}

			void AutoUpdateServerConfigWindow::InitializeComponent()
			{
				System::ComponentModel::ComponentResourceManager *resources = new System::ComponentModel::ComponentResourceManager(AutoUpdateServerConfigWindow::typeid);
				this->serverList = new System::Windows::Forms::ListBox();
				this->flowLayoutPanel1 = new System::Windows::Forms::FlowLayoutPanel();
				this->addServerButton = new System::Windows::Forms::Button();
				this->removeSelectedServersButton = new System::Windows::Forms::Button();
				this->flowLayoutPanel2 = new System::Windows::Forms::FlowLayoutPanel();
				this->cancelButton = new System::Windows::Forms::Button();
				this->okButton = new System::Windows::Forms::Button();
				this->helpButton1 = new MeGUI::core::gui::HelpButton();
				this->flowLayoutPanel3 = new System::Windows::Forms::FlowLayoutPanel();
				this->label1 = new System::Windows::Forms::Label();
				this->subList = new System::Windows::Forms::ComboBox();
				this->flowLayoutPanel2->SuspendLayout();
				this->flowLayoutPanel3->SuspendLayout();
				this->SuspendLayout();
				// 
				// serverList
				// 
				this->serverList->Dock = System::Windows::Forms::DockStyle::Fill;
				this->serverList->FormattingEnabled = true;
				this->serverList->Location = new System::Drawing::Point(0, 28);
				this->serverList->Name = "serverList";
				this->serverList->Size = new System::Drawing::Size(379, 293);
				this->serverList->TabIndex = 0;
				// 
				// flowLayoutPanel1
				// 
				this->flowLayoutPanel1->AutoSize = true;
				this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->flowLayoutPanel1->Location = new System::Drawing::Point(0, 321);
				this->flowLayoutPanel1->Name = "flowLayoutPanel1";
				this->flowLayoutPanel1->Size = new System::Drawing::Size(379, 0);
				this->flowLayoutPanel1->TabIndex = 2;
				// 
				// addServerButton
				// 
				this->addServerButton->AutoSize = true;
				this->addServerButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->addServerButton->Location = new System::Drawing::Point(87, 3);
				this->addServerButton->Name = "addServerButton";
				this->addServerButton->Size = new System::Drawing::Size(48, 23);
				this->addServerButton->TabIndex = 0;
				this->addServerButton->Text = "Add...";
				this->addServerButton->UseVisualStyleBackColor = true;
				this->addServerButton->Click += new System::EventHandler(this, &AutoUpdateServerConfigWindow::addServerButton_Click);
				// 
				// removeSelectedServersButton
				// 
				this->removeSelectedServersButton->AutoSize = true;
				this->removeSelectedServersButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->removeSelectedServersButton->Location = new System::Drawing::Point(141, 3);
				this->removeSelectedServersButton->Name = "removeSelectedServersButton";
				this->removeSelectedServersButton->Size = new System::Drawing::Size(99, 23);
				this->removeSelectedServersButton->TabIndex = 1;
				this->removeSelectedServersButton->Text = "Remove selected";
				this->removeSelectedServersButton->UseVisualStyleBackColor = true;
				this->removeSelectedServersButton->Click += new System::EventHandler(this, &AutoUpdateServerConfigWindow::removeSelectedServersButton_Click);
				// 
				// flowLayoutPanel2
				// 
				this->flowLayoutPanel2->AutoSize = true;
				this->flowLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->flowLayoutPanel2->Controls->Add(this->cancelButton);
				this->flowLayoutPanel2->Controls->Add(this->okButton);
				this->flowLayoutPanel2->Controls->Add(this->helpButton1);
				this->flowLayoutPanel2->Controls->Add(this->removeSelectedServersButton);
				this->flowLayoutPanel2->Controls->Add(this->addServerButton);
				this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->flowLayoutPanel2->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
				this->flowLayoutPanel2->Location = new System::Drawing::Point(0, 321);
				this->flowLayoutPanel2->Name = "flowLayoutPanel2";
				this->flowLayoutPanel2->Size = new System::Drawing::Size(379, 29);
				this->flowLayoutPanel2->TabIndex = 3;
				// 
				// cancelButton
				// 
				this->cancelButton->AutoSize = true;
				this->cancelButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				this->cancelButton->Location = new System::Drawing::Point(327, 3);
				this->cancelButton->Name = "cancelButton";
				this->cancelButton->Size = new System::Drawing::Size(49, 23);
				this->cancelButton->TabIndex = 1;
				this->cancelButton->Text = "Cancel";
				this->cancelButton->UseVisualStyleBackColor = true;
				// 
				// okButton
				// 
				this->okButton->AutoSize = true;
				this->okButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->okButton->Location = new System::Drawing::Point(290, 3);
				this->okButton->Name = "okButton";
				this->okButton->Size = new System::Drawing::Size(31, 23);
				this->okButton->TabIndex = 0;
				this->okButton->Text = "OK";
				this->okButton->UseVisualStyleBackColor = true;
				// 
				// helpButton1
				// 
				this->helpButton1->setArticleName("AutoUpdate");
				this->helpButton1->AutoSize = true;
				this->helpButton1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->helpButton1->Location = new System::Drawing::Point(246, 3);
				this->helpButton1->Name = "helpButton1";
				this->helpButton1->Size = new System::Drawing::Size(38, 23);
				this->helpButton1->TabIndex = 2;
				// 
				// flowLayoutPanel3
				// 
				this->flowLayoutPanel3->Controls->Add(this->label1);
				this->flowLayoutPanel3->Controls->Add(this->subList);
				this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Top;
				this->flowLayoutPanel3->Location = new System::Drawing::Point(0, 0);
				this->flowLayoutPanel3->Name = "flowLayoutPanel3";
				this->flowLayoutPanel3->Size = new System::Drawing::Size(379, 28);
				this->flowLayoutPanel3->TabIndex = 4;
				// 
				// label1
				// 
				this->label1->Location = new System::Drawing::Point(3, 0);
				this->label1->Name = "label1";
				this->label1->Padding = new System::Windows::Forms::Padding(3);
				this->label1->Size = new System::Drawing::Size(114, 23);
				this->label1->TabIndex = 2;
				this->label1->Text = "Auto-update servers";
				this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				// 
				// subList
				// 
				this->subList->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right)));
				this->subList->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->subList->FormattingEnabled = true;
				this->subList->Location = new System::Drawing::Point(123, 3);
				this->subList->Name = "subList";
				this->subList->Size = new System::Drawing::Size(222, 21);
				this->subList->TabIndex = 3;
				this->subList->SelectedIndexChanged += new System::EventHandler(this, &AutoUpdateServerConfigWindow::subList_SelectedIndexChanged);
				// 
				// AutoUpdateServerConfigWindow
				// 
				this->AutoScaleDimensions = new System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = new System::Drawing::Size(379, 350);
				this->Controls->Add(this->serverList);
				this->Controls->Add(this->flowLayoutPanel1);
				this->Controls->Add(this->flowLayoutPanel2);
				this->Controls->Add(this->flowLayoutPanel3);
				this->Font = new System::Drawing::Font("Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (static_cast<unsigned char>(0)));
				this->Icon = (static_cast<System::Drawing::Icon*>(resources->GetObject("$this.Icon")));
				this->Name = "AutoUpdateServerConfigWindow";
				this->Text = "AutoUpdateServerConfigWindow";
				this->flowLayoutPanel2->ResumeLayout(false);
				this->flowLayoutPanel2->PerformLayout();
				this->flowLayoutPanel3->ResumeLayout(false);
				this->ResumeLayout(false);
				this->PerformLayout();

			}

			void AutoUpdateServerConfigWindow::InitializeInstanceFields()
			{
				oldTitle = "";
				oldIndex = -1;
				delete components;
			}
		}
	}
}