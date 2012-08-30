#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <gtk/gtk.h>
 #include <libintl.h>
   

using namespace std;


#define BSIZE 5
/*
#define NOP 0
#define KING 1
#define GOLD 2
#define SILV 3
#define UPSILV 4
#define BISH 5 
#define UPBISH 6
#define ROCK 7
#define UPROCK 8
#define PAWN 9
#define UPPAWN 10
*/

#include "area.h"

typedef size_t uint;
typedef unsigned char byte;

void hello( GtkWidget *widget, gpointer   data )
{
    g_print ("Hello World\n");
}

class viewBoard
{
private:
	Area p;
	GtkWidget *window;
	GtkWidget *table;
	GtkWidget *cells[BSIZE][BSIZE];
	GtkWidget *labls[BSIZE][BSIZE];
	GtkWidget *vboxs[BSIZE][BSIZE];
	int size;
public:
	viewBoard()
	{
	//	gtk_init(NULL, NULL);
		
		
		
		size=BSIZE;
		
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		table  = gtk_table_new(BSIZE, BSIZE, false);
		gtk_window_set_title(GTK_WINDOW(window), "table" );
		
		GdkColor color;
	    color.red = 10000;
	    color.blue = 40000;
	    color.green = 10000;
		
		
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cells[i][j] = gtk_frame_new(NULL);
				labls[i][j] = gtk_label_new("X");
				vboxs[i][j] = gtk_event_box_new();
				
				gtk_widget_set_size_request (cells[i][j], 50, 50);
				gtk_table_attach_defaults(GTK_TABLE(table), cells[i][j], i, i+1, j, j+1);
				
				gtk_container_add(GTK_CONTAINER(cells[i][j]), vboxs[i][j]);
				gtk_container_add(GTK_CONTAINER(vboxs[i][j]), labls[i][j]);
				
				gtk_widget_modify_bg (vboxs[i][j], GTK_STATE_NORMAL, &color);
				
			}
		}
		gtk_container_add(GTK_CONTAINER(window), table);
	    gtk_widget_show_all(window);
	    g_signal_connect(G_OBJECT(window), "destroy" , G_CALLBACK(gtk_main_quit), NULL);
	    gtk_main();
		
	}
};

int main(int argc, char* argv[])
{
	gtk_init(&argc, &argv);
	viewBoard b;
	return 0;
	
}