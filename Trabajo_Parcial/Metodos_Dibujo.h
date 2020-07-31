#ifndef METODOS_DIBUJO
#define METODOS_DIBUJO
#include"CNodo.h"
using namespace System::Drawing;
using namespace System::Windows::Forms;

#define ancho 68
#define alto 50

void Draw_Arrow(Graphics^g, int xini, int yini, int xfin, int yfin, int mode) {
	g->DrawLine(Pens::Black, xini, yini, xfin, yfin);
	Point p1 = Point(xfin, yfin);
	Point p2;
	Point p3;

	switch (mode)
	{
	case 1://derecha

		p2 = Point(xfin - 8, yfin + 8);
		p3 = Point(xfin - 8, yfin - 8);
		break;
	case 2://abajo

		p2 = Point(xfin + 8, yfin - 8);
		p3 = Point(xfin - 8, yfin - 8);
		break;
	case 3://arriba
		p2 = Point(xfin + 8, yfin + 8);
		p3 = Point(xfin - 8, yfin + 8);
		break;
	case 4://izquierda
		p2 = Point(xfin + 8, yfin - 8);
		p3 = Point(xfin + 8, yfin + 8);
		break;
	default:
		break;
		
	}
	cli::array<Point>^tri = { p1,p2,p3 };
	g->FillPolygon(Brushes::Black, tri);
}
void Draw_Inicio(Graphics^g,int x, int y) {
		g->DrawString("Inicio", SystemFonts::DefaultFont, Brushes::Black, 0, y - 20);
		g->DrawLine(Pens::Black, 15, y - 10, 15, y + alto / 2);
		Draw_Arrow(g, 15, y + alto / 2, x - 10, y + alto / 2, 1);
}
void Draw_boxes(Graphics^g,CNodo*aux,System::String^dat,int* x,int y,int xini,int i) {
	dat = gcnew System::String(aux->Get_Dato());



	*x = *x + (2 * xini*(i == 0 ? 0 : 1)) - 10;
	g->DrawRectangle(Pens::Black, *x, y, ancho, alto);
	g->DrawString(dat, SystemFonts::DefaultFont, Brushes::Black, *x + 35 - (dat->Length * 4), y + 20);

	
}

void Draw_final(Graphics^g, int x, int y) {
	g->DrawLine(Pens::Black, x + ancho, y + alto / 2, x + ancho + 20, y + alto / 2);
	Draw_Arrow(g, x + ancho + 20, y + alto / 2, x + ancho + 20, y + alto / 2 + 20, 2);
	g->DrawLine(Pens::Black, x + ancho + 10, y + alto / 2 + 25, x + ancho + 30, y + alto / 2 + 25);
	g->DrawLine(Pens::Black, x + ancho + 15, y + alto / 2 + 30, x + ancho + 25, y + alto / 2 + 30);
	g->DrawLine(Pens::Black, x + ancho + 18, y + alto / 2 + 35, x + ancho + 22, y + alto / 2 + 35);
}

void Draw_Final_circular(Graphics^g, int x, int y,int xini) {
	g->DrawLine(Pens::Black, x + ancho, y + (alto / 2), x + ancho + 20, y + (alto / 2));
	g->DrawLine(Pens::Black,x + ancho + 20, y + (alto / 2), x + ancho + 20, y + alto  + 20);
	g->DrawLine(Pens::Black, x + ancho + 20, y + alto + 20, xini-10 + (ancho / 2), y + alto  + 20);
	Draw_Arrow(g, xini -10+ (ancho / 2), y + alto  + 20, xini-10 + (ancho / 2), y + alto, 3);
}

void Draw_Final_DobCirc(Graphics^g, int x, int y, int xini) {

	g->DrawLine(Pens::Black, x + ancho, y + (alto / 4), x + ancho + 20, y + (alto / 4));
	g->DrawLine(Pens::Black, x + ancho + 20, y + (alto / 4), x + ancho + 20, y + alto + 20);
	g->DrawLine(Pens::Black, x + ancho + 20, y + alto + 20, xini-10 + (ancho / 4), y + alto + 20);
	Draw_Arrow(g, xini-10 + (ancho / 4), y + alto + 20, xini-10 + (ancho / 4), y + alto, 3);

	g->DrawLine(Pens::Black, xini-10 + (ancho *3/4), y + alto + 10, xini-10 + (ancho *3/4), y + alto);
	g->DrawLine(Pens::Black, x + ancho, y + (alto *3/4), x + ancho + 10, y + (alto *3/4));
	g->DrawLine(Pens::Black, x + ancho + 10, y + (alto *3/4), x + ancho + 10, y + alto + 10);
	g->DrawLine(Pens::Black, x + ancho + 10, y + alto + 10, xini-10 + (ancho*3/4), y + alto + 10);
	Draw_Arrow(g, x+ancho+10, y + (alto*3/4), x+ancho, y + (alto*3/4), 4);

}

void Draw_Rear(Graphics^g,int x,int y) {
	g->DrawString("Rear", SystemFonts::DefaultFont, Brushes::Black, x + ancho/2 - 16, y - alto);
	Draw_Arrow(g, x + ancho / 2, y - alto + 8, x + ancho / 2, y, 2);
}

#endif // !METODOS_DIBUJO

