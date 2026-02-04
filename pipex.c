/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:34:24 by adakhama          #+#    #+#             */
/*   Updated: 2026/01/23 17:20:21 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fd_in, int fd_out, char *cmd1, char *cmd2)
{
    int   fd_pipe[2];
    int   status;
    pid_t child1;
    pid_t child2;    
	
	pipe(fd_pipe);
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "));
    if (child1 == 0)
        child_one(fd_in, cmd1);
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    if (child2 == 0)
        child_two(fd_out, cmd2);
    close(fd_pipe[0]);
    close(fd_pipe[1]);
    waitpid(child1, &status, 0);
}
