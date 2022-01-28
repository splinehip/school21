/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_masks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:41 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 15:47:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_MASKS_H
# define EVENTS_MASKS_H

enum	e_events
{
	KEYPRESS			= 2,
	KEYRELEASE			= 3,
	BUTTONPRESS			= 4,
	BUTTONRELEASE		= 5,
	MOTIONNOTIFY		= 6,
	ENTERNOTIFY			= 7,
	LEAVENOTIFY			= 8,
	FOCUSIN				= 9,
	FOCUSOUT			= 10,
	KEYMAPNOTIFY		= 11,
	EXPOSE				= 12,
	GRAPHICSEXPOSE		= 13,
	NOEXPOSE			= 14,
	VISIBILITYNOTIFY	= 15,
	CREATENOTIFY		= 16,
	DESTROYNOTIFY		= 17,
	UNMAPNOTIFY			= 18,
	MAPNOTIFY			= 19,
	MAPREQUEST			= 20,
	REPARENTNOTIFY		= 21,
	CONFIGURENOTIFY		= 22,
	CONFIGUREREQUEST	= 23,
	GRAVITYNOTIFY		= 24,
	RESIZEREQUEST		= 25,
	CIRCULATENOTIFY		= 26,
	CIRCULATEREQUEST	= 27,
	PROPERTYNOTIFY		= 28,
	SELECTIONCLEAR		= 29,
	SELECTIONREQUEST	= 30,
	SELECTIONNOTIFY		= 31,
	COLORMAPNOTIFY		= 32,
	CLIENTMESSAGE		= 33,
	MAPPINGNOTIFY		= 34,
	GENERICEVENT		= 35,
	LASTEVENT			= 36,
};

enum	e_masks
{
	NOEVENTMASK					= 0L,
	KEYPRESSMASK				= (1L << 0),
	KEYRELEASEMASK				= (1L << 1),
	BUTTONPRESSMASK				= (1L << 2),
	BUTTONRELEASEMASK			= (1L << 3),
	ENTERWINDOWMASK				= (1L << 4),
	LEAVEWINDOWMASK				= (1L << 5),
	POINTERMOTIONMASK			= (1L << 6),
	POINTERMOTIONHINTMASK		= (1L << 7),
	BUTTON1MOTIONMASK			= (1L << 8),
	BUTTON2MOTIONMASK			= (1L << 9),
	BUTTON3MOTIONMASK			= (1L << 10),
	BUTTON4MOTIONMASK			= (1L << 11),
	BUTTON5MOTIONMASK			= (1L << 12),
	BUTTONMOTIONMASK			= (1L << 13),
	KEYMAPSTATEMASK				= (1L << 14),
	EXPOSUREMASK				= (1L << 15),
	VISIBILITYCHANGEMASK		= (1L << 16),
	STRUCTURENOTIFYMASK			= (1L << 17),
	RESIZEREDIRECTMASK			= (1L << 18),
	SUBSTRUCTURENOTIFYMASK		= (1L << 19),
	SUBSTRUCTUREREDIRECTMASK	= (1L << 20),
	FOCUSCHANGEMASK				= (1L << 21),
	PROPERTYCHANGEMASK			= (1L << 22),
	COLORMAPCHANGEMASK			= (1L << 23),
	OWNERGRABBUTTONMASK			= (1L << 24),
};

#endif