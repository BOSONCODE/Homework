"""
迷宫的奖赏函数设计为:
红框是agent, 进行游戏的探索
黑框是墙，墙的reward为-1
红框是目的地，reward为1
其他框的reward为0

"""

from maze_env import Maze
from RL_brain import QLearningTable
import matplotlib.pyplot as plt


def update():
    x = []; y = [];
    for episode in range(300):
        observation = env.reset()
        while True:
            env.render()
            action = RL.choose_action(str(observation))
            observation_, reward, done = env.step(action)
            RL.learn(str(observation), action, reward, str(observation_))
            #s = s_
            observation = observation_
            #如果当前阶段已经完成了，那么done就为True
            if done:
                break
        x.append(episode)
        y.append(reward)
    print('game over')
    '''
    env.destroy()
    plt.clf()
    plt.plot(x, y, lw=1, color='navy')
    plt.xlabel('iteration')
    plt.ylabel('loss')
    plt.xlim([0, 100])
    plt.ylim([-10, 10])
    plt.title('Q-Learning')
    plt.show()
    '''

if __name__ == "__main__":
    env = Maze()
    RL = QLearningTable(actions=list(range(env.n_actions)))
    env.after(100, update)
    env.mainloop()
    RL.plot_cost()
