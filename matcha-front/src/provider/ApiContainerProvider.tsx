import App from '@/App';
import { ApiContainer } from '@/utils/api';
import axios from 'axios';
import React from 'react';

const apiContainer = new ApiContainer(axios);

export const ApiContainers = React.createContext<ApiContainer>(apiContainer);

export const ApiProvider = () => {
  return (
    <>
      <ApiContainers.Provider value={apiContainer}>
        <App />
      </ApiContainers.Provider>
    </>
  );
};
