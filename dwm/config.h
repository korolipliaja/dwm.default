/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#000000";
static const char col_gray3[]       = "#C5C8C6";
static const char col_gray4[]       = "#C5C8C6";
static const char col_cyan[]        = "#1E2024";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  "#838583" },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "8", "9", "0" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "firefox",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "TelegramDesktop",  NULL,       NULL,       1 << 6,       0,           -1 },
        { "discord",  NULL,       NULL,       1 << 6,       0,           -1 },
	{ "steam",  NULL,       NULL,       1 << 5,       0,           -1 },
	{ "Ledger Live",  NULL,       NULL,       1 << 4,       0,           -1 },


};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ ALTKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ALTKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ALTKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },








/* helper for spawning shell commands in the pre dwm-5.0 fashion */

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-W", "1248", "-X", "318",  "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const char *mic[] = { "amixer", "set","Capture", "toggle", NULL };
static const char *brightnessup[] = { "light", "-A","10", NULL };
static const char *brightnessdown[] = { "light", "-U", "10", NULL };
static const char *volm[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-20%", NULL };
static const char *volp[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+20%", NULL };
static const char *vols[] = { "pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *firefox[] =   { "firefox", NULL };
static const char *telegram[] =  { "telegram-desktop", NULL };
static const char *nemo[] =      { "nemo", NULL };
static const char *suspend[] =      { "systemctl", "suspend", NULL };
static const char *pmosmonn[] =      { "xrandr", "--output", "eDP", "--off", "--output", "HDMI-A-0", "--mode", "1920x1080", NULL };
static const char *pmosmonn2[] =      { "xrandr", "--output", "eDP", "--mode", "1920x1080", "--output", "HDMI-A-0", "--mode", "1920x1080", NULL };
static const char *pmosmonn3[] =      { "xrandr", "--output", "HDMI-A-0", "--mode", "1920x1080", "--right-of", "eDP", "--mode", "1920x1080", NULL };
static const char *Discord[] = { "Discord", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL };
static const char *flameshotcb[] = { "flameshot", "full", "--clipboard", NULL };
static const char *monitor[] = { "xset", "dpms", "force", "off", NULL };
static const Key keys[] = {
	/* modifier                     key        function        argument */
        { 0, 0x1008ff02, spawn, {.v = brightnessup} },
        { 0, 0x1008ff03, spawn, {.v = brightnessdown} },
        { 0, 0x1008ffb2, spawn, {.v = mic} },
        { 0, 0x1008ff59, spawn, {.v = pmosmonn} },
        { MODKEY, 0x1008ff59, spawn, {.v = pmosmonn2} },
        { MODKEY|ShiftMask, 0x1008ff59, spawn, {.v = pmosmonn3} },
	{ ALTKEY,                       XK_space,      spawn,          {.v = dmenucmd } },
	{ ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ ALTKEY,                       XK_n,      togglebar,      {0} },
	{ ALTKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ ALTKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ ALTKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ ALTKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ ALTKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ ALTKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ ALTKEY,                       XK_Return, zoom,           {0} },
	{ ALTKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ ALTKEY,                       XK_f,      setlayout,      {.v = &layouts[0]} },
	{ ALTKEY,                       XK_v,      setlayout,      {.v = &layouts[1]} },
	{ ALTKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_8,                      4)
	TAGKEYS(                        XK_9,                      5)
        TAGKEYS(                        XK_0,                      6)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ 0,                             0x1008ff13,  spawn,          {.v=volp } }, /* прибавить громкость */
        { 0,                             0x1008ff11,  spawn,          {.v=volm } }, /* убавить громкость */
        { 0,                             0x1008ff12,   spawn,          {.v=vols } }, /* mуte */
	{ ControlMask,                            XK_Print,  spawn,          {.v = flameshot} },
	{ 0,                            XK_Print,  spawn,          {.v = flameshotcb } },
	{ ALTKEY,            	        XK_y,   spawn,          {.v = nemo } }, /* запуск nemo */
	{ ALTKEY,             		XK_t,    spawn,          {.v = telegram } }, /* запуск telegram */
	{ ALTKEY,             		XK_c,    spawn,          {.v = firefox } }, /* запуск firefox */
	{ ALTKEY,             		XK_p,    spawn,          {.v = Discord } }, /* запуск discord */
        { MODKEY|ShiftMask,            		XK_s,    spawn,          {.v = suspend } },/* sleep mode */
        { MODKEY|ShiftMask,            		XK_d,    spawn,          {.v = monitor } },/* sleep mode */



	



};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
/*	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },*/
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

