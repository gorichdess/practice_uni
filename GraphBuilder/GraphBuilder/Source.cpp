#include "GraphB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vcclr.h>

using namespace GraphBuilder;

std::string ConvertString(System::String^ s) {
    std::string str;
    str.resize(s->Length);
    for (int i = 0; i < s->Length; ++i)
        str[i] = s[i];
    return str;
}

void AddGraphLabelWithColor(FlowLayoutPanel^ panel, Color color, String^ text)
{
    Panel^ colorPanel = gcnew Panel();
    colorPanel->BackColor = color;
    colorPanel->Width = 20;
    colorPanel->Height = 20;

    Label^ nameLabel = gcnew Label();
    System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 14);
    nameLabel->Font = font;
    nameLabel->Text = text;

    panel->Controls->Add(colorPanel);
    panel->Controls->Add(nameLabel);
}

void GraphB::Graph_KeyDown(Object^ sender, KeyEventArgs^ e) {
    float compressionX = 1;
    float compressionY = 1;
    switch (e->KeyCode)
    {
    case Keys::Right:
        compressionX += 0.1f;
        break;
    case Keys::Left:
        compressionX -= 0.1f;
        compressionX = Math::Max(0.1f, compressionX);
        break;
    case Keys::Up:
        compressionY += 0.1f;
        break;
    case Keys::Down:
        compressionY -= 0.1f;
        compressionY = Math::Max(0.1f, compressionY);
        break;
    default:
        return;
    }

    for each (Graph ^ graph in GraphB::graphs)
    {
        if (graph->GetName() == selectedGraph) {
            auto points = graph->GetValues();
            for (int i = 0; i < points->Count; i++) {
                PointF point = points[i];
                point.X *= compressionX;
                point.Y *= compressionY;
                points[i] = point; 
            }
        }
    }
    BuildGraph();
}

System::Void GraphB::openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
    openFileDialog1->Title = "Select file";
    openFileDialog1->InitialDirectory = "C:\\";

    // Фільтр для файлів, які можна вибрати (лише .txt файли)
    openFileDialog1->Filter = "Text files (*.txt)|*.txt";

    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        GraphB::selectedFile = openFileDialog1->FileName;
    }
}

System::Void GraphB::GraphB_Load(System::Object^ sender, System::EventArgs^ e){
}

System::Void GraphB::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e){
}
System::Void GraphB::XzoomPos_Click(System::Object^ sender, System::EventArgs^ e){
    if (zoomX >= 0.1) {
        zoomX -= 0.1;
    }
    BuildGraph();
}
System::Void GraphB::XzoomNeg_Click(System::Object^ sender, System::EventArgs^ e) {
    if (zoomX <= 2) {
        zoomX +=0.1;
    }
    BuildGraph();
}
System::Void GraphB::YzoomPos_Click(System::Object^ sender, System::EventArgs^ e){
    if (zoomY >= 0.1) {
        zoomY -= 0.1;
    }
    BuildGraph();
}
System::Void GraphB::YzoomNeg_Click(System::Object^ sender, System::EventArgs^ e){
    if (zoomY <= 2) {
        zoomY += 0.1;
    }
    BuildGraph();
}

System::Void GraphB::Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    Graphics^ graphic = pictureBox1->CreateGraphics();
    graphic->Clear(Color::White);
    flowLayoutPanel1->Controls->Clear();
    graphs->Clear();
    InitializeComboBox();
    delete graphic;
}

System::Void GraphB::chooseColor_Click(System::Object^ sender, System::EventArgs^ e) {
    ColorDialog^ MyDialog = gcnew ColorDialog();
    MyDialog->ShowHelp = true;
    MyDialog->Color = textBox1->ForeColor;
    if (MyDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        graphColor = MyDialog->Color;
    }
}

void GraphB::okButton_Click(System::Object^ sender, System::EventArgs^ e) {

    if (GraphB::selectedFile == nullptr) {
        MessageBox::Show("Please select a file first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (textBox1->Text ==  "") {
        MessageBox::Show("Please enter a name for the chart.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    std::string filename = ConvertString(GraphB::selectedFile);
    std::ifstream file(filename);
    std::cout << filename;

    if (!file.is_open()) {
        MessageBox::Show("Error opening file: " + GraphB::selectedFile, "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    for each (Graph ^ graph in graphs) {
        if (graph->GetName() == textBox1->Text) {
            MessageBox::Show("A chart with the same name already exists: " + textBox1->Text, "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
    }

    Graph^ graph = gcnew Graph();
    Pen^ pen= pen = gcnew Pen(graphColor, 1.0f);
    graphColor = Color::DarkBlue;

    graph->AddPen(pen);
    float x, y;
    while (file >> x >> y) {
        graph->AddPoint(PointF(x, y));
    }
    graph->SetName(textBox1->Text);
    textBox1->Text = "";
    graphs->Add(graph);
    file.close();
    GraphB::selectedFile = nullptr;
    GraphB::selectedGraph = nullptr;
    BuildGraph();
    InitializeComboBox();
}


System::Void GraphB::BuildGraph() {
    
    int width = pictureBox1->Width;
    int height = pictureBox1->Height;

    float xCenter = width / 2;
    float yCenter = height / 2;
    float spacingY = (height / 25)/zoomX;
    float spacingX = (width / 25)/zoomY;
    Graphics^ graphic = pictureBox1->CreateGraphics();
    graphic->Clear(Color::White);

    Pen^ pen = gcnew Pen(Color::LightGray, 1.0f);
    for (int i = width / 2; i < width; i += spacingX) {
        graphic->DrawLine(pen, float(i), 0.0, float(i), float(height));
        graphic->DrawLine(pen, float(width - i), 0.0, float(width - i), float(height));
    }
    for (int i = height / 2; i < height; i += spacingY) {
        graphic->DrawLine(pen, 0.0, float(i), float(width), float(i));
        graphic->DrawLine(pen, 0.0, float(height - i), float(width), float(height - i));
    }


    pen->Color = Color::Black;
    //X line
    graphic->DrawLine(pen, 0.0, yCenter, float(width), yCenter);
    graphic->DrawLine(pen, float(width), yCenter, float(width) - 10, yCenter - 10);
    graphic->DrawLine(pen, float(width), yCenter, float(width) - 10, yCenter + 10);

    //Y line
    graphic->DrawLine(pen, xCenter, 0.0, xCenter, float(height));
    graphic->DrawLine(pen, xCenter, 0.0, xCenter - 10, 0.0 + 10);
    graphic->DrawLine(pen, xCenter, 0.0, xCenter + 10, 0.0 + 10);


    System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 12);
    Brush^ brush = gcnew SolidBrush(Color::DarkGray);
    graphic->DrawString("Y", font, brush, xCenter - 25, 0);
    graphic->DrawString("X", font, brush, float(width) - 25, yCenter - 25);
    graphic->DrawString(String::Format("{0:0.0}", zoomX), font, brush, xCenter + spacingX, yCenter);
    graphic->DrawString(String::Format("{0:0.0}", zoomY), font, brush, xCenter-25, yCenter - spacingY);

    flowLayoutPanel1->Controls->Clear();
    for each (Graph ^ graph in graphs) {
        Pen^ pen1 = graph->GetPen();
        AddGraphLabelWithColor(flowLayoutPanel1, pen1->Color, graph->GetName());
        Generic::List<PointF>^ points = graph->GetValues();
        for (int i = 0; i < points->Count - 1; i++) {
            PointF point1 = points[i];
            PointF point2 = points[i + 1];
            if (!point1.IsEmpty && !point2.IsEmpty)
            {
                float x = point1.X;
                float y = point1.Y;
                float x1 = point2.X;
                float y1 = point2.Y;
                graphic->DrawLine(pen1, xCenter + x * spacingX, yCenter - y * spacingY, xCenter + x1 * spacingX, yCenter - y1 * spacingY);
            }
        }
    }


    delete pen;
    delete graphic;
    delete font;
    delete brush;
}

System::Void GraphB::selectGraph_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    selectedGraph = selectGraph->SelectedItem->ToString();
}

void GraphB::InitializeComboBox() {
    selectGraph->Items->Clear();

    for each (Graph ^ graph in GraphB::graphs)
    {
        GraphB::selectGraph->Items->Add(graph->GetName());
    }
}

System::Void GraphB::moveButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (xMove->Text == nullptr || yMove->Text == nullptr) {
        MessageBox::Show("Please enter the movement number for the chart.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (selectedGraph == nullptr) {
        MessageBox::Show("Please select the chart.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    for each (Graph ^ graph in GraphB::graphs)
    {
        if (graph->GetName() == selectedGraph) {
            if (graph->GetName() == selectedGraph) {
                auto points = graph->GetValues();
                for (int i = 0; i < points->Count; i++) {
                    try
                    {
                        float x_Move = Convert::ToSingle(xMove->Text);
                        float y_Move = Convert::ToSingle(yMove->Text);
                        PointF point = points[i];
                        point.X += x_Move;
                        point.Y += y_Move;
                        points[i] = point;
                    }
                    catch (FormatException^)
                    {
                        MessageBox::Show("Please enter a valid number.");
                        return;
                    }
                }
            }
        }
    }
    BuildGraph();
}
