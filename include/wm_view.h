#ifndef WM_VIEW_H
#define WM_VIEW_H

#include <stdbool.h>
#include <wayland-server.h>
#include <wlr/types/wlr_xdg_shell.h>

struct wm_view{
    struct wl_list link;  // wm_server::wm_views

    bool mapped;

    /*
     * The surfaces of the wlr_xdg_surface are displayed on coordinates (x + sx, y + sy) with actual 
     *     width = scale*wlr_surface->current.width
     *     height = scale*wlr_surface->current.height
     */
    int x;
    int y;
    double scale;

    struct wlr_xdg_surface* wlr_xdg_surface;

    struct wl_listener map;
    struct wl_listener unmap;
    struct wl_listener destroy;
};

void wm_view_init(struct wm_view* view, struct wlr_xdg_surface* surface);
void wm_view_destroy(struct wm_view* view);

void wm_view_update(struct wm_view* view, struct timespec when);

#endif
