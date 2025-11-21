/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimplegurajani <dimplegurajani@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:01:46 by dimpleguraj       #+#    #+#             */
/*   Updated: 2025/11/20 16:51:16 by dimpleguraj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void find_dp(int *arr, int *dp, int *prev, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        dp[i] = 1;
        prev[i] = -1;
        j = 0;
        while (j < i)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
            j++;
        }
        i++;
    }
}

static int find_lis_end(int *dp, int size, int *len)
{
    int i;
    int max_i;

    *len = dp[0];
    max_i = 0;
    i = 1;
    while (i < size)
    {
        if (dp[i] > *len)
        {
            *len = dp[i];
            max_i = i;
        }
        i++;
    }
    return (max_i);
}

static void build_lis(int *arr, int *prev, int end, int len, int *lis)
{
    int     i;

    i = len - 1;
    while(end != -1 && i >= 0)
    {
        lis[i] = arr[end];
        end = prev[end];
        i--;
    }
}

int *compute_lis_indices(t_node *a, int *lis_len)
{
    int *dp;
    int *prev;
    int *lis;
    int *arr;
    int end;
    int size;

    size = list_size(a);
    arr = stack_to_array(a, size);
    dp = (int *)malloc(sizeof(int) * size);
    prev = (int *)malloc(sizeof(int) * size);
    if (!dp || !prev || !arr)
        return (NULL);
    find_dp(arr, dp, prev, size);
    end = find_lis_end(dp, size, lis_len);
    lis = (int *)malloc(sizeof(int) * (*lis_len));
    if (!lis)
    {
        free(arr);
        free(dp);
        free(prev);
        return (NULL);
    }
    build_lis(arr, prev, end, *lis_len, lis);
    free(arr);
    free(dp);
    free(prev);
    return (lis);
}


