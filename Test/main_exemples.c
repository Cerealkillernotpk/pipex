/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exemples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:25:39 by adakhama          #+#    #+#             */
/*   Updated: 2026/01/13 17:54:31 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// int main()
// {
// 	int 	fd;

// 	fd = open("exemple.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	ft_printf("This is printed in exemple.txt\n");

// 	return (0);
// }

// int main ()
// {
// 	if (access("exemple.txt", R_OK) != -1)
// 		ft_printf("I have the permission\n");
// 	else
// 		ft_printf("I don't have the permission\n");
// 	return (0);
// }

// int main ()
// {
//     char *args[3];

//     args[0] = "ls";
//     args[1] = "-l";
//     args[2] = NULL;
//     execve("/bin/ls", args, NULL);
//     printf("This line will not be executed.\n");
//     return (0);
// }

// int main()
// {
//     pid_t pid;

//     pid = fork();
//     if (pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == 0)
//         printf("This is the child process. (pid: %d)\n", getpid());
//     else
//         printf("This is the parent process. (pid: %d)\n", getpid());
//     return (0);
// }


// int main()
// {
//     int fd[2];
//     pid_t pid;
//     char buffer[13];

//     if (pipe(fd) == -1)
//     {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }
//     pid = fork();
//     if (pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }
//     if (pid == 0)
//     {
//         close(fd[0]); // close the read end of the pipe
//         write(fd[1], "Hello parent!", 13);
//         close(fd[1]); // close the write end of the pipe
//         exit(EXIT_SUCCESS);
//     }
//     else
//     {
//         close(fd[1]); // close the write end of the pipe
//         read(fd[0], buffer, 13);
//         close(fd[0]); // close the read end of the pipe
//         printf("Message from child: '%s'\n", buffer);
//         exit(EXIT_SUCCESS);
//     }
// }

int main()
{
	int fd_in;
	// int fd_out;
	char *str;
	
    fd_in = open("in", O_WRONLY | O_CREAT);
	// fd_out = open("../out", O_WRONLY | O_CREAT);
	// dup2(fd_out, STDOUT_FILENO);
	// close(fd_out);
	str = get_next_line(fd_in);
	while(str)
	{
		ft_printf("%s", str);
		str = get_next_line(fd_in);
	}
	close(fd_in);
	return (0);
}
