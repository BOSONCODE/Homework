import gym
from RL_brain import QLearningTable

env = gym.make('MountainCar-v0')
env = env.unwrapped

print(env.action_space)
print(env.observation_space)
print(env.observation_space.high)
print(env.observation_space.low)


RL = QLearningTable(actions = list(range(3)))
total_steps = 0


for i_episode in range(10):
    observation = env.reset()
    ep_r = 0
    while True:
        env.render()
        action = RL.choose_action(str(observation)) 
        observation_, reward, done, info = env.step(action)
        position, velocity = observation_
        # the higher the better
        reward = abs(position - (-0.5))     # r in [0, 1]        
        RL.learn(str(observation), action, reward, str(observation_))        
        ep_r += reward
        if done:
            get = '| Get' if observation_[0] >= env.unwrapped.goal_position else '| ----'
            print('Epi: ', i_episode, 
                    get,
                    '| Ep_r: ', round(ep_r, 4),
                    '| Epsilon: ', 
                    round(RL.epsilon, 2))
            break
        observation = observation_
        total_steps += 1

RL.plot_cost()
