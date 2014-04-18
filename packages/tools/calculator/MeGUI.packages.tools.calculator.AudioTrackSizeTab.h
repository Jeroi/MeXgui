#pragma once

#include "core/details/CodecManager.h"
#include "core/util/VideoUtil.h"
#include "core/util/DragDropUtil.h"
#include "packages/audio/AudioJob.h"
#include "core/util/LogItem.h"
#include "core/util/FileSize.h"
#include "core/details/Streams.h"
#include <QString>

// ****************************************************************************
// 
// Copyright (C) 2005-2009  Doom9 & al
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// 
// ****************************************************************************




//using namespace System::Collections::Generic;



//using namespace System::Data;



//using namespace System::Text;



using namespace MeXgui::core::details;
using namespace MeXgui::core::util;

using namespace MediaInfoWrapper;

namespace MeXgui
{
	namespace packages
	{
		namespace tools
		{
			namespace calculator
			{
				class AudioTrackSizeTab : public UserControl
				{
//C# TO C++ CONVERTER TODO TASK: There is no direct equivalent to .NET events in native C++:
//					public event EventHandler SomethingChanged;

				private:
					bool updating;

					public:
					~AudioTrackSizeTab()
					{
						this->Dispose(true);
					}

//C# TO C++ CONVERTER WARNING: Unlike C#, there is no automatic call to this finalizer method in native C++:
					private:
					void Finalize()
					{
						this->Dispose(false);
					}

				public:
					AudioTrackSizeTab();

					void SetAudioJob(AudioJob *job);

				private:
					qint64 length;
				public:
					const qint64 &getPlayLength() const;
					void setPlayLength(const qint64 &value);

				private:
					void audio1Bitrate_ValueChanged();

					void raiseEvent();

					void selectAudioFile(const QString &file);

					const QString filter;

					void selectButton_Click();

				public:
					const AudioBitrateCalculationStream &getStream() const;

				private:
					void size_SelectionChanged(object *sender, const QString &val);

					void audio1Type_SelectedIndexChanged();

					void removeLink_LinkClicked();

					void AudioTrackSizeTab_Enter();



					/// <summary> 
					/// Required designer variable.
					/// </summary>
					System::ComponentModel::IContainer *components;

					/// <summary> 
					/// Clean up any resources being used.
					/// </summary>
					/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
					void Dispose(bool disposing);


					/// <summary> 
					/// Required method for Designer support - do not modify 
					/// the contents of this method with the code editor.
					/// </summary>
					void InitializeComponent();


					System::Windows::Forms::Label *label2;
					System::Windows::Forms::Label *label1;
					System::Windows::Forms::NumericUpDown *audio1Bitrate;
					System::Windows::Forms::Button *selectButton;
					System::Windows::Forms::ComboBox *audio1Type;
					System::Windows::Forms::Label *audio1TypeLabel;
					System::Windows::Forms::OpenFileDialog *openFileDialog;
					System::Windows::Forms::Label *audioLabel;
					System::Windows::Forms::TextBox *name;
					System::Windows::Forms::TextBox *size;
					System::Windows::Forms::LinkLabel *removeLink;
					System::Windows::Forms::ToolTip *removalToolTip;

				private:
					void InitializeInstanceFields();
				};
			}
		}
	}
}