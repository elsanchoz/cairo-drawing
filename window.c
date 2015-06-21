#include "main.h"

gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{ 
  	UNUSED(data); 
  	UNUSED(widget);
	
	int i = 0;
	
	for (i = 0; i < 15; i++){

		double a = (double)(rand() % 1000); 
		double b = (double)(rand() % 1000); 
		double c = (double)(rand() % 1000); 
		double d = (double)(rand() % 1000);
		double e = (double)(rand() % 1000);  
		double f = (double)(rand() % 1000);  
		double g = (double)(rand() % 1000); 
		
		printf("a: %f\n", a);
		printf("b: %f\n", b);
		printf("c: %f\n", c);
		printf("d: %f\n", d);
		printf("e: %f\n", e);
		printf("f: %f\n", f);
		printf("g: %f\n", g);
		
		cairo_set_source_rgb (cr, 0, 0, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, a, b);
		cairo_line_to (cr, 200, 400);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, 0, 0, 10);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, b);
		cairo_line_to (cr, 300, a);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, 0, 10, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, a, 70);
		cairo_line_to (cr, a, b);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, 10, 0, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, b);
		cairo_line_to (cr, g, f);
		cairo_stroke (cr);
		
		cairo_set_source_rgb (cr, f, e, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, b);
		cairo_line_to (cr, g, f);
		cairo_stroke (cr);
		
		cairo_set_source_rgb (cr, f, e, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, b);
		cairo_line_to (cr, g, f);
		cairo_stroke (cr);
		
		cairo_set_source_rgb (cr, f, e, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, b);
		cairo_line_to (cr, g, f);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, 0, 0, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, f);
		cairo_rel_curve_to (cr, 200, d, 500, d, 200, 0);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, 0, 0, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 200, c, a, 10, 200, a);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, 0, 0, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 200, g, b, 100, g, 300);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, f, e, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 200, a, 500, 200, b, d);
		cairo_stroke (cr);
		
		cairo_set_source_rgb (cr, 0, 0, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 200, g, b, 100, g, e);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, g, e, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 200, a, 500, 200, b, f);
		cairo_stroke (cr);
	
		cairo_set_source_rgb (cr, g, e, 0);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 1000, a, 500, 200, b, g);
		cairo_stroke (cr);
		
		cairo_set_source_rgb (cr, 0, f, a);
		cairo_set_line_width (cr, 0.5);
		cairo_move_to (cr, 50, 70);
		cairo_rel_curve_to (cr, 1600, a, 500, 200, b, f);
		cairo_stroke (cr);
		
	}
 return FALSE;
}

int main( int argc, char *argv[] )
{	
	GtkWidget *window;
	GtkWidget *drawing;

	gtk_init (&argc, &argv);
   
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	drawing = gtk_drawing_area_new ();
	gtk_container_add(GTK_CONTAINER(window), drawing);
	
	gtk_window_fullscreen(GTK_WINDOW(window));
	
	gtk_window_set_title (GTK_WINDOW (window), "Modern Art");

	gtk_widget_queue_draw (drawing);
	
	srand (time(NULL));
	
	printf("Thank You.");
	
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect (G_OBJECT (drawing), "draw", G_CALLBACK (draw_callback), NULL);

	gtk_widget_show_all (window);

	gtk_main ();
    
	return 0;
}
