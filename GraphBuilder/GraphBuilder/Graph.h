#pragma once
#include <list>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class Graph {
public:
    Graph() {
        values = gcnew Generic::List<PointF>();
        nameOfGraph = "";
        PenOfGraph = gcnew Pen(Color::Black, 1.0f);
    }

    Graph(Graph^ graph) {
        this->values = graph->values;
        this->nameOfGraph = graph->nameOfGraph;
        this->PenOfGraph = graph->PenOfGraph;
    }

    void AddPen(Pen^ pen) {
        PenOfGraph = pen;
    }

    Pen^ GetPen() {
        return PenOfGraph;
    }

    Generic::List<PointF>^ GetValues() {
        return values;
    }

    String^ GetName() {
        return nameOfGraph;
    }

    void SetName(String^ name) {
        nameOfGraph = name;
    }

    void AddPoint(PointF point) {
        values->Add(point);
    }


private:
    Pen^ PenOfGraph;
    Generic::List<PointF>^ values;
    String^ nameOfGraph;
};