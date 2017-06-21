/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:11:02 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/20 16:06:22 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
# define ANSI_H

# define A_CODE(...) A_START __VA_ARGS__ A_END
# define A_START "\e["
# define A_END "m"

/*
** Styles
*/
# define A_CLEAR "0"
# define A_BOLD "1"
# define A_DARK "2"
# define A_ULINE "4"
# define A_BLINK "5"
# define A_INVERT "7"
# define A_NONE "8"

/*
** Dark Text Color
*/
# define A_BLACK "30"
# define A_RED "31"
# define A_GREEN "32"
# define A_YELLOW "33"
# define A_BLUE "34"
# define A_MAGENTA "35"
# define A_CYAN "36"
# define A_WHITE "37"

/*
** Light Text Color
*/
# define A_GRAY "90"
# define A_LRED "91"
# define A_LGREEN "92"
# define A_LYELLOW "93"
# define A_LBLUE "94"
# define A_LMAGENTA "95"
# define A_LCYAN "96"
# define A_LWHITE "97"

/*
** Dark Background Color
*/
# define A_BBLACK "40"
# define A_BRED "41"
# define A_BGREEN "42"
# define A_BYELLOW "43"
# define A_BBLUE "44"
# define A_BMAGENTA "45"
# define A_BCYAN "46"
# define A_BWHITE "47"

/*
** Light Background Color
*/
# define A_BGRAY "100"
# define A_BLRED "101"
# define A_BLGREEN "102"
# define A_BLYELLOW "103"
# define A_BLBLUE "104"
# define A_BLMAGENTA "105"
# define A_BLCYAN "106"
# define A_BLWHITE "107"

#endif
